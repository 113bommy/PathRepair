#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mamx = 6;
  for (int i = 1; i <= b; i++) {
    if (b >= i + 1 && c >= i + 2) {
      mamx = i + i + 1 + i + 2;
    }
  }
  cout << mamx << endl;
}
