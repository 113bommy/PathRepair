#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, MAX = 0, pos = 0;
  cin >> n;
  int v[n + 1];
  map<int, int> M;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    M[v[i]]++;
    if (M[v[i]] > MAX) {
      MAX = M[v[i]];
      pos = i;
    }
  }
  cout << n - MAX << endl;
  for (int i = pos; i < n - 1; i++) {
    if (v[i] > v[i + 1]) {
      v[i + 1] += abs(v[i] - v[i + 1]);
      cout << 1 << " " << i + 2 << " " << i + 1 << endl;
    } else if (v[i] < v[i + 1]) {
      v[i + 1] -= abs(v[i] - v[i + 1]);
      cout << 2 << " " << i + 2 << " " << i + 1 << endl;
    }
  }
  for (int i = pos; i > 0; i--) {
    if (v[i] > v[i - 1]) {
      v[i - 1] += abs(v[i] - v[i - 1]);
      cout << 1 << " " << i - 1 + 1 << " " << i + 1 << endl;
    } else if (v[i] < v[i - 1]) {
      v[i - 1] -= abs(v[i] - v[i - 1]);
      cout << 2 << " " << i - 1 + 1 << " " << i + 1 << endl;
    }
  }
  return 0;
}
