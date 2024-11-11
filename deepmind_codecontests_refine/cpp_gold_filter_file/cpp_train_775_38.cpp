#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  int x = (n1 - 1) / k1 + 1;
  int y = (n2 - 1) / k2 + 1;
  cout << (n1 > n2 ? "First" : "Second");
}
