#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int c;
  cin >> n >> m;
  c = n / m;
  vector<int> dis(m, c);
  c = n % m;
  for (int i = 0; i < c; i++) {
    dis[i]++;
  }
  cout << dis[0];
  for (int i = 1; i < m; i++) {
    cout << " " << dis[i];
  }
  cout << endl;
}
