#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int tot = a + b + 1;
  for (int g = tot - a; g <= tot; g++) cout << g << " ";
  for (int g = b; g >= 1; g--) cout << g << " ";
}
