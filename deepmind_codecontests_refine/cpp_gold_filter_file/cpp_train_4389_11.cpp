#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;
  int bor = 0;
  vector<long long> ans(k, 0);
  for (int i = k - 1; i >= 0; i--) {
    if (bor == 0) {
      if (t[i] >= s[i]) {
        ans[i] = t[i] - s[i];
        bor = 0;
      } else {
        bor = 1;
        ans[i] = t[i] - s[i];
        ans[i] += 26;
      }
    } else {
      if (t[i] > s[i]) {
        ans[i] = t[i] - s[i] - 1;
        bor = 0;
      } else {
        ans[i] = t[i] - s[i] - 1;
        ans[i] += 26;
        bor = 1;
      }
    }
  }
  int rem = 0;
  for (int i = 0; i < k; i++) {
    if (rem == 0) {
      if (ans[i] % 2 == 0) {
        ans[i] /= 2;
        rem = 0;
      } else {
        ans[i] /= 2;
        rem = 1;
      }
    } else {
      if (ans[i] % 2 == 0) {
        ans[i] = (ans[i] + 26) / 2;
        rem = 0;
      } else {
        ans[i] = (ans[i] + 26) / 2;
        rem = 1;
      }
    }
  }
  int car = 0;
  for (int i = k - 1; i >= 0; i--) {
    if (car == 0) {
      ans[i] = ans[i] + (s[i] - 97);
      if (ans[i] >= 26) {
        ans[i] %= 26;
        car = 1;
      } else
        car = 0;
    } else {
      ans[i] = ans[i] + (s[i] - 97) + car;
      if (ans[i] >= 26) {
        ans[i] %= 26;
        car = 1;
      } else
        car = 0;
    }
  }
  for (int i = 0; i < k; i++) cout << char(ans[i] + 97);
}
