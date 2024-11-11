#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string a[2] = {"Malvika", "Akshat"};
  cin >> n >> m;
  cout << a[(m * n) % 2] << endl;
  return 0;
}
