#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, i;
  cin >> n >> m;
  long long int in[n], fi[n], si = 0, sf = 0;
  for (i = 0; i < n; i++) {
    cin >> in[i] >> fi[i];
    si += in[i];
    sf += fi[i];
  }
  if (sf > m)
    cout << "-1\n";
  else {
    vector<long long int> v;
    for (i = 0; i < n; i++) v.push_back(in[i] - fi[i]);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long int k = si - m;
    long long int cnt = 0;
    if (k == 0)
      cout << "0\n";
    else {
      for (i = 0; i < v.size(); i++) {
        k -= v[i];
        cnt++;
        if (k < 0) break;
      }
      cout << cnt << "\n";
    }
  }
}
