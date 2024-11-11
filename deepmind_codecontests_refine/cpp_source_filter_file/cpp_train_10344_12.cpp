#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, a;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a;
    v[a] = i;
  }
  int m;
  long vasya = 0, petya = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a;
    vasya += v[a];
    petya += (n - v[a] + 1);
  }
  cout << vasya << " " << petya << endl;
}
