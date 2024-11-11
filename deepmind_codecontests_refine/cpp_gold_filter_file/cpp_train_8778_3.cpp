#include <bits/stdc++.h>
using namespace std;
bool sortcol(vector<int> &v1, vector<int> &v2) { return v1[1] < v2[1]; }
int main() {
  long long int n, m, x, y, total = 0;
  cin >> n >> m;
  int i;
  vector<vector<int>> v;
  for (i = 0; i < m; i++) {
    vector<int> z;
    scanf("%lld %lld", &x, &y);
    z.push_back(x);
    z.push_back(y);
    v.push_back(z);
  }
  sort(v.begin(), v.end(), sortcol);
  auto itr = v.rbegin();
  for (itr; itr != v.rend(); itr++) {
    if (n > (*itr)[0]) {
      total += (*itr)[0] * (*itr)[1];
      n = n - (*itr)[0];
    } else {
      total += n * (*itr)[1];
      break;
    }
  }
  cout << total;
}
