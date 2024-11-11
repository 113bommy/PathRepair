#include <bits/stdc++.h>
using namespace std;
int owe[101] = {0};
int main() {
  int n, m, a, b, c;
  long long int count = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    owe[a] += c;
    owe[b] -= c;
  }
  for (int i = 1; i <= n; i++) {
    if (owe[i] > 0) count += owe[i];
  }
  cout << count;
}
