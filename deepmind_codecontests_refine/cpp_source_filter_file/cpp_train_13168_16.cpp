#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, s;
  cin >> n >> s;
  map<int, long long> S, B;
  for (int a_ : vector<char>(n)) {
    char c;
    int p, q;
    cin >> c >> p >> q;
    if (c == 'S')
      S[p] += q;
    else
      B[p] += q;
  }
  int i = 0;
  while (s < S.size()) S.erase(S.begin());
  for (auto x = S.rbegin(); x != S.rend(); ++x) {
    cout << "S " << x->first << " " << x->second << '\n';
  }
  i = 0;
  for (auto x = B.rbegin(); x != B.rend(); ++x) {
    i++;
    cout << "B " << x->first << " " << x->second << '\n';
    if (i == s) break;
  }
  return 0;
}
