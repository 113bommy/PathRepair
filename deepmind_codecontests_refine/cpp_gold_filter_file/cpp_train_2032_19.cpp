#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int a[N], b[N];
pair<int, int> flag1, flag21, flag22;
pair<long long, pair<int, int> > two1[N * N], two2[N * N], two3;
int num1 = 1, num2 = 1;
int main() {
  int n, m;
  long long s1 = 0;
  long long s2 = 1e18;
  long long s3 = 1e18;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s1 += a[i];
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    s1 -= b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      long long cur = abs(s1 + 2 * b[j] - 2 * a[i]);
      if (cur < s2) {
        s2 = cur;
        flag1 = make_pair(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      two1[num1++] = make_pair((a[i] + a[j]), make_pair(i, j));
    }
  }
  num1--;
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      two2[num2++] = make_pair((b[i] + b[j]), make_pair(i, j));
    }
  }
  num2--;
  if (num1 != 0 && num2 != 0) {
    sort(two1 + 1, two1 + 1 + num1);
    for (int i = 1; i <= num2; i++) {
      long long b1 = two2[i].first;
      two3 = make_pair((s1 + 2 * b1 + 1) / 2, make_pair(1, 1));
      int x = lower_bound(two1 + 1, two1 + 1 + num1, two3) - (two1 + 1);
      for (int j = max(1, x); j <= min(num1, x + 1); j++) {
        long long a1 = two1[j].first;
        long long cur = abs(s1 + 2 * b1 - 2 * a1);
        if (cur < s3) {
          s3 = cur;
          flag21 = make_pair(two1[j].second.first, two1[j].second.second);
          flag22 = make_pair(two2[i].second.first, two2[i].second.second);
        }
      }
    }
  }
  long long flag = min(min(abs(s1), abs(s2)), abs(s3));
  cout << flag << endl;
  if (flag == abs(s1)) {
    printf("0\n");
  } else if (flag == abs(s2)) {
    printf("1\n");
    printf("%d %d\n", flag1.first, flag1.second);
  } else {
    printf("2\n");
    printf("%d %d\n", flag21.first, flag22.first);
    printf("%d %d\n", flag21.second, flag22.second);
  }
  return 0;
}
