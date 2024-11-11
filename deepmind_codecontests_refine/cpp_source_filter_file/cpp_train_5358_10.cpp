#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a + 1; i++) cout << i + b << " ";
  for (int i = 1; i <= b; i++) cout << i << " ";
  return 0;
}
