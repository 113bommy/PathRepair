#include <bits/stdc++.h>
using namespace ::std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<char> v;
  vector<int> pref;
  pref.push_back(0);
  v.push_back('Y');
  int mr = 0;
  int tr = 0;
  for (int i = 0; i < n; i++) {
    v.push_back(s[i]);
    if (s[i] == 'Y') {
      pref.push_back(pref[i]);
    } else {
      pref.push_back(pref[i] + 1);
    }
    if (s[i] == 'N') {
      tr++;
    } else {
      mr = max(mr, tr);
      tr = 0;
    }
  }
  mr = max(mr, tr);
  if (mr > k) {
    cout << "NO\n";
    return 0;
  } else if (mr == k) {
    cout << "YES\n";
    return 0;
  }
  pref.push_back((*(--pref.end())));
  v.push_back('Y');
  for (int i = k; i < n + 1; i++) {
    if (pref[i] - pref[i - k - 1] != k) continue;
    if (v[i - k - 1] == 'N' || v[i + 1] == 'N') continue;
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
}
