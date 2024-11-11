#include <bits/stdc++.h>
using namespace std;
int n, m, flag, num;
long long ans = 0;
vector<int> a, b;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &flag, &num);
    if (!flag)
      a.push_back(num);
    else
      b.push_back(num);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int lena = a.size(), lenb = b.size();
  if (!lena) {
    int num1 = 1, num2 = 1;
    for (int i = 1; i < lenb; i++) {
      if (b[i] == b[i - 1])
        num1++;
      else
        break;
    }
    for (int i = lenb - 2; i >= 0; i--) {
      if (b[i] == b[i + 1])
        num2++;
      else
        break;
    }
    if (num1 == lenb)
      ans = 1LL * num1 * (num1 - 1) * (num1 - 2) / 6;
    else
      ans = 1LL * num1 * num2 * (lenb - num1 - num2) +
            1LL * num1 * num2 * (num2 - 1) / 2 +
            1LL * num2 * num1 * (num1 - 1) / 2;
  } else if (!lenb) {
    int num1 = 1, num2 = 1;
    for (int i = 1; i < lena; i++) {
      if (a[i] == a[i - 1])
        num1++;
      else
        break;
    }
    for (int i = lena - 2; i >= 0; i--) {
      if (a[i] == a[i + 1])
        num2++;
      else
        break;
    }
    if (num1 == lena)
      ans = 1LL * num1 * (num1 - 1) * (num1 - 2) / 6;
    else
      ans = 1LL * num1 * num2 * (lena - num1 - num2) +
            1LL * num1 * num2 * (num2 - 1) / 2 +
            1LL * num2 * num1 * (num1 - 1) / 2;
  } else if (a[lena - 1] < b[0]) {
    int num1 = 1, num2 = 1;
    for (int i = lena - 2; i >= 0; i--) {
      if (a[i] == a[i + 1])
        num1++;
      else
        break;
    }
    for (int i = 1; i < lenb; i++) {
      if (b[i] == b[i - 1])
        num2++;
      else
        break;
    }
    ans = 1LL * num2 * num1 * (num1 - 1) / 2 +
          1LL * num1 * num2 * (num2 - 1) / 2 +
          1LL * num1 * num2 * (n - num1 - num2);
  } else if (b[lenb - 1] < a[0]) {
    int num1 = 1, num2 = 1;
    for (int i = lenb - 2; i >= 0; i--) {
      if (b[i] == b[i + 1])
        num1++;
      else
        break;
    }
    for (int i = 1; i < lena; i++) {
      if (a[i] == a[i - 1])
        num2++;
      else
        break;
    }
    ans = 1LL * num2 * num1 * (num1 - 1) / 2 +
          1LL * num1 * num2 * (num2 - 1) / 2 +
          1LL * num1 * num2 * (n - num1 - num2);
  } else {
    for (int i = 0; i < lena; i++) {
      int rpos = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
      int lpos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
      int len = rpos - lpos - 1;
      ans += 1LL * len * (len - 1) / 2 + 1LL * len * (lenb - len) +
             1LL * (lpos + 1) * (lenb - rpos);
    }
    for (int i = 0; i < lenb; i++) {
      int rpos = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
      int lpos = lower_bound(a.begin(), a.end(), b[i]) - a.begin() - 1;
      int len = rpos - lpos - 1;
      ans += 1LL * len * (len - 1) / 2 + 1LL * len * (lena - len) +
             1LL * (lpos + 1) * (lena - rpos);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
