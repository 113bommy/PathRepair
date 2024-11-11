#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> c(3);
  vector<int> m(3);
  float cs = 0, ms = 0;
  for (int i = 0; i < 3; i++) {
    cin >> c[i];
    cs += c[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> m[i];
    ms += c[i];
  }
  int n;
  cin >> n;
  int x = ceil(cs / 5) + ceil(ms / 10);
  if (x > n)
    cout << "NO";
  else
    cout << "YES";
}
