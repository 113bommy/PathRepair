#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string names[n];
  int scores[n];
  map<string, long long> map1;
  long long maxi = 0;
  string winner;
  for (int i = 0; i < n; i++) {
    cin >> names[i] >> scores[i];
    map1[names[i]] += scores[i];
  }
  for (int i = 0; i < n; i++) {
    maxi = max(map1[names[i]], maxi);
  }
  map<string, long long> map2;
  for (int i = 0; i < n; i++) {
    map2[names[i]] += scores[i];
    if (map1[names[i]] == maxi && map2[names[i]] >= maxi) {
      winner = names[i];
      break;
    }
  }
  cout << winner;
  return 0;
}
