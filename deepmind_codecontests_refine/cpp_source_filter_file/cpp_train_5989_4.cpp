#include <bits/stdc++.h>
using namespace std;
struct vertex {
  int x, y;
};
int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  map<int, int> m, l;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < n; j++) {
      if (v[i][j] == 'C') {
        m[i]++;
        m[j]++;
      }
    }
  }
  int a = 0;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    int c = it->second;
    a += (c - 1) * c / 2;
  }
  for (map<int, int>::iterator it = l.begin(); it != l.end(); it++) {
    int c = it->second;
    a += (c - 1) * c / 2;
  }
  cout << a;
  return 0;
}
