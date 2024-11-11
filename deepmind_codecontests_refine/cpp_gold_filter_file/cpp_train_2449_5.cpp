#include <bits/stdc++.h>
using namespace std;
int main() {
  int A1, A2, B1, B2;
  while (cin >> A1 >> A2 >> B1 >> B2) {
    bool res = false;
    if (-1 <= B2 - A1 && B2 - A1 <= A1 + 2) res = true;
    if (-1 <= B1 - A2 && B1 - A2 <= A2 + 2) res = true;
    puts(res ? "YES" : "NO");
  }
}
