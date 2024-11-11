#include <bits/stdc++.h>
using namespace std;
string s;
int m, k, ans, n, d[1000001], a, b, c;
int main() {
  setlocale(LC_ALL, "Rus");
  cin >> n >> k;
  cout << max(0, n - k + (n * 2));
  return 0;
}
