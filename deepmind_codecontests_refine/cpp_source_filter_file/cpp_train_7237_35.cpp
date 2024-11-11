#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (n % 2 == 0) a = (n - a + 1);
  cout << (a + 1) / 2;
}
