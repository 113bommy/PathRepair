#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
long long v[100010];
map<long long, long long> mp;
int main() {
  long long a, b, c, n;
  cin >> a >> b >> c;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> v[i];
    mp[v[i]] = 1;
  }
  sort(v, v + n);
  long long sum = 0;
  int i = 0;
  while (v[i] <= b && i < n) {
    i++;
  }
  for (int j = i; v[j] < c; j++) {
    sum += mp[i];
  }
  cout << sum << endl;
  return 0;
}
