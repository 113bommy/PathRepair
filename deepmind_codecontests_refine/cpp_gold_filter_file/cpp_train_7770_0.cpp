#include <bits/stdc++.h>
using namespace std;
ifstream fin("AAtest.in.txt");
vector<int> v[30];
string s, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> s >> t;
  int n = s.size();
  for (int(i) = (0); ((i)) < ((n)); ((i))++) v[s[i] - 'a'].emplace_back(i);
  vector<int> in;
  for (int(i) = (0); ((i)) < ((26)); ((i))++) in.emplace_back(0);
  bool ei = 0;
  int ku = -1;
  int vas = 1;
  for (int(i) = (0); ((i)) < ((t.size())); ((i))++) {
    int k = t[i] - 'a';
    if (!v[k].size()) {
      ei = 1;
      break;
    } else {
      while (in[k] < v[k].size() and v[k][in[k]] <= ku) in[k]++;
      if (in[k] == v[k].size()) {
        vas++;
        for (int(i) = (0); ((i)) < ((26)); ((i))++) in[i] = 0;
      }
      ku = v[k][in[k]];
    }
  }
  if (ei) {
    cout << -1;
    return 0;
  } else
    cout << vas;
}
