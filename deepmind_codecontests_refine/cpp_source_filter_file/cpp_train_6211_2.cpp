#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
long long n, m, cnt, ans, mn;
long long used[N];
long long mx;
map<double, int> mp;
char z;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin >> n;
  long long arr[n], b[n], c[n];
  for (int i = 0; i < n; i++) {
    cin >> z >> arr[i] >> z >> b[i] >> z >> z >> c[i];
    mp[(arr[i] + b[i]) / c[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (mp[(arr[i] + b[i]) / c[i]]) v.push_back(mp[(arr[i] + b[i]) / c[i]]);
  }
  for (auto it : v) cout << it << " ";
}
