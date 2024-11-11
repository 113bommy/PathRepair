#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, i, j, p, ho[100005];
  vector<pair<long long int, long long int>> x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    ho[i] = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    ho[a]++;
    x.push_back(make_pair(a, b));
  }
  for (i = 0; i < n; i++) {
    a = x[i].second;
    b = ho[a];
    y.push_back(make_pair(n - 1 + b, (n - 1) - b));
  }
  for (i = 0; i < n; i++) {
    cout << y[i].first << " " << y[i].second << endl;
  }
  return 0;
}
