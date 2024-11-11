#include <bits/stdc++.h>
using namespace std;
int n, p[1111], c[1111];
vector<pair<int, int> > ve;
int main() {
  int a;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a;
    c[i] = a;
  }
  int s = 1;
  cin >> p[0];
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    if (p[i] != p[c[i]]) {
      s++;
    }
  }
  cout << s;
  return 0;
}
