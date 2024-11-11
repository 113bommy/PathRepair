#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100];
void swapi(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
int main() {
  int n, m, b[100][2];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    a[i].second = i;
    cin >> a[i].first;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    a[i].first = i % 2;
  }
  for (int i = 0; i < n; i++) {
    swapi(a[i].first, a[i].second);
  }
  sort(a, a + n);
  for (int i = 0; i < m; i++) cin >> b[i][0] >> b[i][1];
  for (int i = 0; i < n; i++) {
    cout << a[i].second << " ";
  }
}
