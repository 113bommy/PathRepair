#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
bool check(int mid) {
  int cnt = 0, l = 0;
  while (l < n) {
    cnt++;
    int r = l + mid;
    if (r >= n) break;
    while (r > l && s[r - 1] != ' ' && s[l - 1] != '-') r--;
    if (l == r) return 0;
    l = r;
  }
  return cnt <= k;
}
int l, mid, r;
int main() {
  cin >> k;
  for (int i = 0; i < 2; i++) getline(cin, s);
  n = s.size();
  r = n + 1;
  while (r - l > 1) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
  return 0;
}
