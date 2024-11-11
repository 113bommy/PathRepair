#include <bits/stdc++.h>
using namespace std;
int main() {
  string m, n;
  int a = 1;
  cin >> n >> m;
  for (int i = 0; i < m.size(); i++)
    if (m[i] == n[a]) a++;
  cout << a << endl;
  return 0;
}
