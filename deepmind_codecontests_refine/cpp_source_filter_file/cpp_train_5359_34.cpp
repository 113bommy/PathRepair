#include <bits/stdc++.h>
using namespace std;
bool happy_gir[200];
bool happy_g[200];
int main() {
  int n, m;
  cin >> n >> m;
  int b;
  cin >> b;
  int tmp;
  for (int i = 0; i < b; i++) {
    cin >> tmp;
    happy_g[tmp] = 1;
  }
  int g;
  cin >> g;
  for (int i = 0; i < g; i++) {
    cin >> tmp;
    happy_gir[tmp] = 1;
  }
  for (int i = 1; i <= 1000; i++) {
    if ((happy_g[i % n] == 0 && happy_gir[i % m] == 1) ||
        (happy_g[i % n] == 1 && happy_gir[i % m] == 0) ||
        (happy_g[i % n] == 1 && happy_gir[i % m] == 1)) {
      happy_g[i % n] = 1;
      happy_gir[i % m] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (happy_g[i] == 0) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (happy_gir[i] == 0) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
  return 0;
}
