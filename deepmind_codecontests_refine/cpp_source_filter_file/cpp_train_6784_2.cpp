#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  vector<int> pref(a.size());
  pref[0] = b[0] - '0';
  for (int i = 1; i < a.size(); ++i) {
    pref[i] = pref[i - 1] + a[i] - '0';
  }
  int sum = 0;
  for (int i = 0; i < b.size(); ++i) {
    sum += b[i] - '0';
  }
  int res = 0;
  for (int i = 0; i < a.size() - b.size(); ++i) {
    if (sum % 2 == (pref[i + b.size()] - pref[i]) % 2) res++;
  }
  if (sum % 2 == pref[b.size() - 1] % 2) res++;
  cout << res;
  return 0;
}
