#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int c = n * m;
  if (c % 2 == 0)
    cout << "Malvika" << endl;
  else
    cout << "Akshat" << endl;
  return 0;
}
