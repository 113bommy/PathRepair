#include <bits/stdc++.h>
using namespace std;
bool boy[105];
bool girl[105];
int main() {
  int n, m;
  cin >> n >> m;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int w;
    cin >> w;
    boy[w] = 1;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int w;
    cin >> w;
    girl[w] = 1;
  }
  for (int i = 0; i < n * m * 50; i++) {
    int g = i % m;
    int q = i % n;
    if (boy[q] && !girl[g]) {
      girl[g] = 1;
    } else if (!boy[q] && girl[g]) {
      boy[q] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (boy[i] == 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (girl[i] == 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
