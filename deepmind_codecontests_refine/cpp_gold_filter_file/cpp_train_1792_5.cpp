#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int pocz = 0;
  int konc = 0;
  vector<pair<pair<int, int>, char> > V;
  for (int i = 1; i < S.length(); i++)
    if (S[i] != S[i - 1]) {
      V.push_back({{pocz, i - 1}, S[i - 1]});
      pocz = i;
    }
  V.push_back({{pocz, S.length() - 1}, S[pocz]});
  if (V.size() % 2 == 0) {
    cout << 0;
    return 0;
  }
  int pointer1 = V.size() / 2;
  int pointer2 = V.size() / 2;
  int ile = V[pointer1].first.second - V[pointer1].first.first + 2;
  if (ile <= 2) {
    cout << 0;
    return 0;
  }
  pointer1--;
  pointer2++;
  while (pointer1 != -1) {
    if (V[pointer1].first.second - V[pointer1].first.first + 1 +
            V[pointer2].first.second - V[pointer2].first.first + 1 <
        3) {
      cout << 0;
      return 0;
    }
    if (V[pointer1].second != V[pointer2].second) {
      cout << 0;
      return 0;
    }
    pointer1--;
    pointer2++;
  }
  cout << ile;
}
