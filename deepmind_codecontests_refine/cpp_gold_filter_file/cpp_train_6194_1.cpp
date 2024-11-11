#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int i, j, t, n, m, k, temp, mini;
  mini = 100000000LL;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m;
    mini = min(m, mini);
  }
  if (mini == 1)
    cout << "-1" << endl;
  else
    cout << "1" << endl;
  return 0;
}
