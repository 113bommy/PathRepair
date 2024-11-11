#include <bits/stdc++.h>
using namespace std;
const long long int INF = 2000000000000000000LL;
const int MOD = 10000007;
int a[1000006];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for (auto c : s) {
    if (c == '0') cnt0++;
    if (c == '1') cnt1++;
    if (c == '2') cnt2++;
  }
  int v = n / 3;
  if (cnt0 == v && cnt1 == v && cnt2 == v) {
    cout << s << "\n";
    ;
    return 0;
  }
  for (int i = n - 1; i >= 0 && cnt0 > v; i--) {
    if (s[i] == '0') {
      if (cnt2 < v) {
        s[i] = '2';
        cnt2++;
        cnt0--;
      } else if (cnt1 < v) {
        s[i] = '1';
        cnt1++;
        cnt0--;
      }
    }
  }
  for (int i = 0; i < n && cnt1 > v; i++) {
    if (s[i] == '1') {
      if (cnt0 < v) {
        s[i] = '0';
        cnt0++;
        cnt1--;
      }
    }
  }
  for (int i = n - 1; i >= 0 && cnt1 > v; i--) {
    if (s[i] == '1') {
      if (cnt2 < v) {
        s[i] = '2';
        cnt2++;
        cnt1--;
      }
    }
  }
  for (int i = 0; i < n && cnt2 > v; i++) {
    if (s[i] == '2') {
      if (cnt0 < v) {
        s[i] = '0';
        cnt0++;
        cnt2--;
      } else if (cnt1 < v) {
        s[i] = '1';
        cnt1++;
        cnt2--;
      }
    }
  }
  cout << s << "\n";
  ;
  return 0;
}
