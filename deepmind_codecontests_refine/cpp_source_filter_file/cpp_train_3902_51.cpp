#include <bits/stdc++.h>
using namespace std;
void print(int n, char c) {
  while (n--) cout << c;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    if (i % 2)
      print(n, '#');
    else {
      if ((i / 2) % 2) {
        print(n - 1, '.');
        cout << "#";
      } else {
        cout << "#";
        print(n - 1, '.');
      }
    }
    cout << endl;
  }
}
