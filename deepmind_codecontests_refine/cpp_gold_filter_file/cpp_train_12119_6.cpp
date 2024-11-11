#include <bits/stdc++.h>
using namespace std;
int v[100000];
int main() {
  int n, m, c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == i) c++;
  }
  if (c != n) {
    for (int i = 0; i < n; i++)
      if (v[v[i]] == i && v[i] != i) {
        cout << c + 2 << endl;
        return 0;
      }
    cout << c + 1 << endl;
  } else
    cout << c << endl;
  return 0;
}
