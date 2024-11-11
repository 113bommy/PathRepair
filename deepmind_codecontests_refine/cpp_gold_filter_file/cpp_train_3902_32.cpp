#include <bits/stdc++.h>
using namespace std;
void print(int n, char c) {
  while (n--) cout << c;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    if (i % 2)
      print(m, '#');
    else {
      if ((i / 2) % 2) {
        print(m - 1, '.');
        cout << "#";
      } else {
        cout << "#";
        print(m - 1, '.');
      }
    }
    cout << endl;
  }
}
