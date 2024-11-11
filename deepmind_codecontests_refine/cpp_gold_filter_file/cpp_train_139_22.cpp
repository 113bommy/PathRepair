#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b = 0;
  cin >> n;
  int a[n][2];
  vector<int> h;
  vector<int> a1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
      if (j % 2 != 0)
        a1.push_back(a[i][j]);
      else
        h.push_back(a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && h[i] == a1[j]) b++;
    }
  }
  cout << b;
}
