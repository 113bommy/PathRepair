#include <bits/stdc++.h>
using namespace std;
int main() {
  long X;
  cin >> X;
  long now = 100;
  int cnt = 0;
  while (now < X) now *= 1.01, cnt++;
  cout << cnt << "\n";
}
