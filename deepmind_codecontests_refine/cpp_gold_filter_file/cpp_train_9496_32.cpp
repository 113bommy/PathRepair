#include <bits/stdc++.h>
using namespace std;
inline long long sub(long long n) { return (n * (n + 1)) / 2; }
inline bool mycomp(string p, string q) {
  return (long long)p.size() < (long long)q.size();
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "? 1 1" << endl;
    string s;
    cin >> s;
    cout << "! " << s << endl;
    return 0;
  }
  cout << "? 1 " << n << endl;
  multiset<string> ms;
  for (long long i = 0; i < sub(n); i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ms.insert(s);
  }
  cout << "? 2 " << n << endl;
  for (long long i = 0; i < sub(n - 1); i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ms.erase(ms.find(s));
  }
  vector<string> arr;
  while (!ms.empty()) {
    arr.push_back(*ms.begin());
    ms.erase(ms.begin());
  }
  sort(arr.begin(), arr.end(), mycomp);
  string ans;
  vector<long long> prev(26, 0);
  for (string s : arr) {
    vector<long long> cur(26, 0);
    for (char c : s) cur[c - 'a']++;
    for (long long i = 0; i < 26; i++) {
      if (cur[i] != prev[i]) ans.push_back(i + 'a');
    }
    prev = cur;
  }
  cout << "! " << ans << endl;
}
