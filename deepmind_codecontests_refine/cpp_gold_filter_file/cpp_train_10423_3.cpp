#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  s += s[((int)(s).size()) - 1] == 'S' ? "" : ".";
  vector<pair<char, int>> A;
  vector<int> pot;
  vector<int> pot2;
  int inc = 0;
  int pt = 0;
  while (s[pt] == 'S' && pt < ((int)(s).size())) pt++;
  char cur = s[pt];
  for (int i = pt; i < ((int)(s).size()); i++) {
    char c = s[i];
    if (c != cur) {
      A.push_back(pair<char, int>(cur, inc));
      cur = c;
      inc = 1;
    } else
      inc++;
  }
  int cand = 0;
  for (int i = 0; i < ((int)(A).size()); i++) {
    if (A[i].first == 'G') {
      cand = A[i].second;
      pot2.push_back(cand);
    } else if (A[i].second == 1 && A[i].first == 'S' && i < ((int)(A).size())) {
      pot.push_back(cand + A[i + 1].second);
    }
  }
  sort(pot.begin(), pot.end());
  sort(pot2.begin(), pot2.end());
  if (((int)(pot2).size()) == 0)
    cout << 0 << endl;
  else if (((int)(pot2).size()) == 1)
    cout << pot2[0] << endl;
  else if (((int)(pot).size()) == 0)
    cout << pot2[((int)(pot2).size()) - 1] + 1 << endl;
  else
    cout << max(pot2[((int)(pot2).size()) - 1] +
                    (((int)(pot2).size()) == 2 ? 0 : 1),
                pot[((int)(pot).size()) - 1] +
                    (((int)(pot2).size()) == 2 ? 0 : 1))
         << endl;
  return 0;
}
