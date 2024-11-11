#include <bits/stdc++.h>
using namespace std;
int brp[26], prv[26];
map<string, int> besar, kecil;
vector<string> v;
bool cmp(string s, string t) { return s.length() < t.length(); }
int main() {
  int n;
  string s;
  cin >> n;
  cout << "? 1 " << n << endl;
  for (int i = 1; i <= (n * (n + 1)) / 2; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    besar[s]++;
  }
  if (n == 1) {
    cout << "! " << s << endl;
    return 0;
  }
  cout << "? 1 " << n - 1 << endl;
  for (int i = 1; i <= ((n - 1) * n) / 2; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    kecil[s]++;
  }
  for (map<string, int>::iterator it = besar.begin(); it != besar.end(); ++it) {
    if (it->second != kecil[it->first]) v.push_back(it->first);
  }
  sort(v.begin(), v.end(), cmp);
  string ans = "";
  for (auto isi : v) {
    memset(brp, 0, sizeof(brp));
    for (int i = 0; i < isi.length(); i++) brp[isi[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
      if (brp[i] > prv[i]) ans += (char)(i + 'a');
    }
    for (int i = 0; i < 26; i++) prv[i] = brp[i];
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
