#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, n, temp;
  string s;
  cin >> n;
  vector<long long> a = {0};
  for (i = 0; i < n; i++) {
    cin >> temp;
    a.push_back(temp);
  }
  a.push_back(1001);
  int maxx = 0, curr = 0;
  for (i = 1; i < n; i++) {
    if (a[i] - a[i - 1] == 1 && a[i + 1] - a[i] == 1) {
      curr++;
      maxx = max(maxx, curr);
    } else
      curr = 0;
  }
  cout << maxx;
  return 0;
}
