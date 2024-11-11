#include <bits/stdc++.h>
using namespace std;
int main() {
  string m, n;
  int a = 1;
  cin >> n >> m;
  for (int i = 0; i < n.size(); i++)
    if (n[i] == m[a]) a++;
  cout << a << endl;
  return 0;
}
