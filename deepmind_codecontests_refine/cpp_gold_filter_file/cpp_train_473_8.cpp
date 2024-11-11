#include <bits/stdc++.h>
using namespace std;
vector<int> l[1000000];
int main() {
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    l[a[i]].push_back(i + 1);
  }
  int q = 0;
  for (int i = 0; i < n; i++) {
    int j = a[i];
    if (a[j - 1] != j) q = 1;
  }
  int m = 1;
  for (int i = 1; i <= n; i++) {
    int z = 0;
    for (std::vector<int>::iterator it = l[i].begin(); it != l[i].end(); ++it) {
      b[*it - 1] = m;
      z = 1;
    }
    if (z == 1) {
      c[m - 1] = i;
      m++;
    }
  }
  if (q == 0) {
    cout << m - 1 << endl;
    for (int i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m - 1; i++) {
      cout << c[i] << " ";
    }
  } else
    cout << "-1";
}
