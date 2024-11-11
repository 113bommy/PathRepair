#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int tot = a + b + 1;
  for (int g = tot - a; g <= tot; g++) cout << g << " ";
  for (int g = 1; g <= b; g++) cout << g << " ";
}
