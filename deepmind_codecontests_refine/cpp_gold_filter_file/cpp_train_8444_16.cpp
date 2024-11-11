#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mamx = 0;
  for (int i = 1; i <= a; i++) {
    if (b >= i + 1 && c >= i + 2) {
      mamx = i + i + 1 + i + 2;
    }
  }
  cout << mamx << endl;
}
