#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (!n && m)
    cout << "Impossible\n";
  else
    cout << n + max(m - n, 0) << " " << n + max(m - 1, 0) << endl;
}
