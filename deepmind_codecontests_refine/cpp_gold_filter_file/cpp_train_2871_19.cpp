#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n / 2; i++)
    if (i % 2 == 0) swap(v[i], v[n - i - 1]);
  cout << v[0];
  for (int i = 1; i < n; i++) cout << " " << v[i];
  cout << endl;
}
