#include <bits/stdc++.h>
using namespace std;
int atk[101], def[101], a[101], b[101];
int input(int n, int m) {
  int temp, k = 0, l = 0;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s >> temp;
    if (s == "ATK") {
      atk[k] = temp;
      k++;
    } else {
      def[l] = temp;
      l++;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> temp;
    a[i] = temp;
  }
  return k;
}
int answer(int n, int m, int k) {
  int h = min(m, k), ans = 0;
  for (int i = 0; i < h; i++) {
    if (a[m - 1 - i] >= atk[i]) {
      ans += a[m - 1 - i] - atk[i];
    } else {
      return ans;
    }
  }
  return ans;
}
int answer_with(int n, int m, int k) {
  int l = n - k, j = 0;
  for (int i = 0; i < m; i++) {
    if (j < l && a[i] > def[j]) {
      j++;
    } else {
      b[i - j] = a[i];
    }
  }
  if (j < l) return 0;
  int ans = 0, h1 = k - 1, h2 = m - l - 1;
  bool flag = true;
  while (h1 != -1 && h2 != -1) {
    if (b[h2] >= atk[h1]) {
      ans += b[h2] - atk[h1];
      h1--;
      h2--;
    } else {
      flag = false;
      h1--;
    }
  }
  if (!flag) return ans;
  while (h2 != -1) {
    ans += b[h2];
    h2--;
  }
  return ans;
}
int main() {
  int n, m, k;
  cin >> n >> m;
  k = input(n, m);
  sort(atk, &atk[k]);
  sort(def, &def[n - k]);
  sort(a, &a[m]);
  if (m > n) {
    int ans1 = answer_with(n, m, k);
    int ans2 = answer(n, m, k);
    if (ans1 > ans2)
      cout << ans1;
    else
      cout << ans2;
  } else {
    cout << answer(n, m, k);
  }
  return 0;
}
