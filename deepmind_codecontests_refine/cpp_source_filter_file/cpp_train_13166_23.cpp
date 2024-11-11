#include <bits/stdc++.h>
using namespace std;
int cost[30];
string S;
map<long long, long long> occ[30];
int main() {
  for (int i = 0; i < 26; i++) cin >> cost[i];
  cin >> S;
  int acc = 0;
  long long res = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    res += occ[S[i] - 'a'][acc];
    acc += cost[S[i] - 'a'];
    occ[S[i] - 'a'][acc]++;
  }
  cout << res << "\n";
}
