#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, x;
  cin >> k >> x;
  for (int j = k - x + 1; j < x + k; j++) cout << j << ' ';
}
