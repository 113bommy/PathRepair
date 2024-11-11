#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  vector<int> v1(n);
  int i = 1;
  int p = n;
  while (p--) {
    if (i != n)
      cout << "? " << i << " " << i + 1 << "\n";
    else
      cout << "? " << n - 2 << " " << n << "\n";
    fflush(stdout);
    int l;
    cin >> l;
    v1.push_back(l);
    i++;
  }
  v[n - 1] = v1[n - 3] + v1[n - 2] - v1[n - 1];
  v[n] = v1[n - 2] - v[n - 1];
  for (i = n - 3; i >= 0; i--) {
    v[i + 1] = v1[i] - v[i + 2];
  }
  cout << "! ";
  for (i = 1; i <= n; i++) {
    cout << v[i] << " ";
  }
  fflush(stdout);
}
