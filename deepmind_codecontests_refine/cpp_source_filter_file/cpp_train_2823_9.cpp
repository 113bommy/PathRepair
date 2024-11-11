#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  string const RANKS = "6789TJQKA";
  char joker;
  cin >> joker;
  string s1, s2;
  cin >> s1 >> s2;
  bool res = false;
  if (s1[1] == joker && s2[1] != joker) {
    res = true;
  } else if (s1[0] == s2[0]) {
    int rank1 = RANKS.find(s1[0]);
    int rank2 = RANKS.find(s2[0]);
    res = rank1 > rank2;
  }
  if (res)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
