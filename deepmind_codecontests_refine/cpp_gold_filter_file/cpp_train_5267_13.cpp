#include <bits/stdc++.h>
using namespace std;
int main() {
  string pos[] = {"A",   "B",   "C",   "D",   "E",   "F",   "G",   "H",   "I",
                  "J",   "K",   "L",   "M",   "N",   "O",   "P",   "Q",   "R",
                  "S",   "T",   "U",   "V",   "W",   "X",   "Y",   "Z",   "Aa",
                  "Ba",  "Ca",  "Da",  "Ea",  "Fa",  "Ga",  "Ha",  "Ia",  "Ja",
                  "Ka",  "La",  "Ma",  "Na",  "Oa",  "Pa",  "Qa",  "Ra",  "Sa",
                  "Ta",  "Ua",  "Va",  "Wa",  "Xa",  "Ya",  "Za",  "Aaa", "Baa",
                  "Caa", "Daa", "Eaa", "Faa", "Gaa", "Haa", "Iaa", "Jaa", "Kaa",
                  "Laa", "Maa", "Naa", "Oaa", "Paa", "Qaa", "Raa", "Saa", "Taa",
                  "Uaa", "Vaa", "Waa", "Xaa", "Yaa", "Zaa"};
  int n, k;
  cin >> n >> k;
  string s[55], names[55];
  for (long long i = 0; i < n - k + 1; ++i) cin >> s[i];
  int c = 0;
  int last = 0;
  vector<string> v;
  int i;
  for (i = 0; i < n - k + 1; ++i) {
    if (s[i] == "NO")
      v.push_back(pos[c]);
    else {
      for (int p = 0; p < k; ++p) {
        v.push_back(pos[c]);
        ++c;
      }
      break;
    }
  }
  for (i = i + 1; i < n - k + 1; ++i) {
    if (s[i] == "YES") {
      v.push_back(pos[c]);
      ++c;
    } else {
      v.push_back(v[v.size() - k + 1]);
    }
  }
  while (v.size() < n) v.push_back(pos[c]);
  for (long long i = 0; i < v.size(); ++i) cout << v[i] << " ";
  return 0;
}
