#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 5;
vector<string> v{
    "H",  "HE", "LI", "BE", "B",  "C",  "N",  "O",  "F",  "NE", "NA", "MG",
    "AL", "SI", "P",  "S",  "CL", "AR", "K",  "CA", "SC", "TI", "V",  "CR",
    "MN", "FE", "CO", "NI", "CU", "ZN", "GA", "GE", "AS", "SE", "BR", "KR",
    "RB", "SR", "Y",  "ZR", "NB", "MO", "TC", "RU", "RH", "PD", "AG", "CD",
    "IN", "SN", "SB", "TE", "I",  "XE", "CS", "BA", "LA", "CE", "PR", "ND",
    "PM", "SM", "EU", "GD", "TB", "DY", "HO", "ER", "TM", "YB", "LU", "HF",
    "TA", "W",  "RE", "OS", "IR", "PT", "AU", "HG", "TL", "PB", "BI", "PO",
    "AT", "RN", "FR", "RA", "AC", "TH", "PA", "U",  "NP", "PU", "AM", "CM",
    "BK", "CF", "ES", "FM", "MD", "NO", "LR", "RF", "DB", "SG", "BH", "HS",
    "MT", "DS", "RG", "CN", "NH", "FL", "MC", "LV", "TS", "OG"};
string t;
bool flag = false;
void DP() {
  vector<bool> f(t.size() + 1);
  f[0] = true;
  for (int i = 0; i < t.size(); i++) {
    if (f[i]) {
      for (string c : v) {
        if (t.substr(i, c.size()) == c) f[i + c.size()] = true;
      }
    }
  }
  cout << (f[f.back()] ? "YES" : "NO") << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  DP();
  return 0;
}
