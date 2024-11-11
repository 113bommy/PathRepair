#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  map<string, string> mm;
  string a, b;
  while (n--) {
    cin >> a >> b;
    mm[b] = a;
  }
  while (m--) {
    cin >> a >> b;
    cout << a << ' ' << b << " #" << mm[b.substr(0, b.size() - 1)] << endl;
  }
}
