#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, n, m;
  cin >> h >> m >> n;
  map<int, int> id;
  vector<int> table(h, -1);
  int ops = 0;
  for (int i = 0; i < n; ++i) {
    char o;
    cin >> o;
    if (o == '+') {
      int d, hash;
      cin >> d >> hash;
      int operations = 0;
      int pos = hash;
      while (table[pos] != -1) {
        operations++;
        pos = (hash + operations * m) % h;
      }
      ops += operations;
      table[pos] = d;
      id[d] = hash;
    } else {
      int d;
      cin >> d;
      table[id[d]] = -1;
      id.erase(d);
    }
  }
  cout << ops << endl;
}
