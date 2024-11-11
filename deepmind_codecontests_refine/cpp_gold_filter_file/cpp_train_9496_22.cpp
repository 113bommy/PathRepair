#include <bits/stdc++.h>
using namespace std;
vector<string> besar, kecil, v[105], sisa;
int brp[26], prv[26], now[26], last[26];
bool cmp(string a, string t) { return a.length() < t.length(); }
int main() {
  int n;
  string s;
  cin >> n;
  if (n <= 3) {
    string ans = "";
    for (int i = 1; i <= n; i++) {
      cout << "? " << i << " " << i << endl;
      cin >> s;
      ans += s;
    }
    cout << "! " << ans << endl;
    return 0;
  }
  cout << "? 1 " << n / 2 << endl;
  for (int i = 1; i <= n / 2; i++) {
    for (int j = i; j <= n / 2; j++) {
      cin >> s;
      sort(s.begin(), s.end());
      besar.push_back(s);
    }
  }
  cout << "? 2 " << n / 2 << endl;
  for (int i = 2; i <= n / 2; i++) {
    for (int j = i; j <= n / 2; j++) {
      cin >> s;
      sort(s.begin(), s.end());
      kecil.push_back(s);
    }
  }
  sort(kecil.begin(), kecil.end());
  sort(besar.begin(), besar.end());
  int j = 0;
  for (int i = 0; i < kecil.size(); i++) {
    while (kecil[i] != besar[j]) {
      sisa.push_back(besar[j]);
      j++;
    }
    j++;
  }
  for (int i = j; i < besar.size(); i++) sisa.push_back(besar[i]);
  sort(sisa.begin(), sisa.end(), cmp);
  string pref = "", suf = "";
  for (auto isi : sisa) {
    for (int i = 0; i < isi.length(); i++) brp[isi[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
      if (brp[i] > prv[i]) pref += (char)(i + 'a');
    }
    for (int i = 0; i < 26; i++) prv[i] = brp[i];
    memset(brp, 0, sizeof(brp));
  }
  cout << "? 1 " << n << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      cin >> s;
      v[s.length()].push_back(s);
    }
  }
  for (int i = 0; i < n; i++) brp[v[n][0][i] - 'a']++;
  for (int i = 1; i <= n / 2; i++) {
    besar.clear();
    for (auto isi : v[n - i]) {
      memset(prv, 0, sizeof(prv));
      for (int j = 0; j < n - i; j++) prv[isi[j] - 'a']++;
      s = "";
      for (int j = 0; j < 26; j++) {
        for (int k = 0; k < brp[j] - prv[j]; k++) s += ((char)('a' + j));
      }
      besar.push_back(s);
    }
    kecil.clear();
    for (int j = 1; j <= i; j++) {
      s = pref.substr(0, j) + suf.substr(0, i - j);
      sort(s.begin(), s.end());
      kecil.push_back(s);
    }
    sort(kecil.begin(), kecil.end());
    sort(besar.begin(), besar.end());
    int idx = besar.size() - 1;
    for (int j = 0; j < kecil.size(); j++) {
      if (kecil[j] != besar[j]) {
        idx = j;
        break;
      }
    }
    memset(now, 0, sizeof(now));
    for (int j = 0; j < i; j++) now[besar[idx][j] - 'a']++;
    for (int j = 0; j < 26; j++) {
      if (now[j] > last[j]) {
        suf += (char)('a' + j);
        break;
      }
    }
    for (int j = 0; j < 26; j++) last[j] = now[j];
  }
  if (n & 1) {
    memset(now, 0, sizeof(now));
    for (int i = 0; i < pref.length(); i++) now[pref[i] - 'a']++;
    for (int i = 0; i < suf.length(); i++) now[suf[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
      if (brp[i] > now[i]) {
        pref += (char)('a' + i);
        break;
      }
    }
  }
  reverse(suf.begin(), suf.end());
  cout << "! " << pref + suf << endl;
  return 0;
}
