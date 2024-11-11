#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
int n, m, k;
int main() {
  cin >> n >> m >> k;
  int s1 = 0;
  int s2 = 0;
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    int aux;
    cin >> aux;
    if (aux == 2) {
      s2++;
      if (s2 > k) {
        s1++;
        s2--;
      }
    } else {
      s1++;
    }
  }
  if (s1 > m) {
    sol += m - s1;
  }
  if (s2 > k) {
    sol += k - s2;
  }
  cout << -sol << endl;
  return 0;
}
