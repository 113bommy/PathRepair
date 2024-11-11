#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int p, n;
  unsigned long long temp;
  cin >> p >> n;
  vector<int> BCKT(p, false);
  for (int i = 0; i < p; i++) {
    cin >> temp;
    if (BCKT[temp % p] == 1) {
      cout << i + 1;
      return 0;
    }
    BCKT[temp % p] = 1;
  }
  cout << -1;
  return 0;
}
