#include <bits/stdc++.h>
using namespace std;
bool f(int x, int y) { return (x > y); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, p = 0, v[40];
  cin >> n;
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c == '4') {
      v[p++] = 2;
      v[p++] = 2;
      v[p++] = 3;
    } else {
      if (c == '6') {
        v[p++] = 3;
        v[p++] = 5;
      } else {
        if (c == '8') {
          v[p++] = 2;
          v[p++] = 2;
          v[p++] = 2;
          v[p++] = 7;
        } else {
          if (c == '9') {
            v[p++] = 3;
            v[p++] = 2;
            v[p++] = 2;
            v[p++] = 7;
          } else {
            if (((c - '0') > 1)) v[p++] = c - '0';
          }
        }
      }
    }
  }
  sort(v, v + p, f);
  for (int i = 0; i < p; i++) {
    cout << v[i];
  }
  cout << endl;
  return 0;
}
