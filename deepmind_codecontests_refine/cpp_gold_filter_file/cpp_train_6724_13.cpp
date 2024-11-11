#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector<int> v;
int main() {
  fast();
  long long a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int start = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] >= v[start] && b >= v[i])
      start = i;
    else
      break;
  }
  int end = n - 1;
  for (int i = n - 2; i > -1; i++) {
    if (v[i] <= v[end] && c <= v[i])
      end = i;
    else
      break;
  }
  int cnt = 0;
  for (int i = start; i <= end; i++) {
    if (v[i] > b && v[i] < c) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
