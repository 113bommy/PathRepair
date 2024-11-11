#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  vector<int> aux(n * n);
  for (int i = 1; i <= n * n; i++) {
    v.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0 + 2 * i; j < n / 2 + 2 * i; j++) {
      cout << v[j] << " " << v[v.size() - 1 - j] << " ";
    }
    cout << endl;
  }
  return 0;
}
