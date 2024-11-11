#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) { return a < b; }
int main() {
  ios_base::sync_with_stdio(false);
  long long n, i, j, k;
  cin >> n;
  vector<string> v;
  string st;
  for (i = 0; i < n; i++) {
    cin >> st;
    v.push_back(st);
  }
  sort(v.begin(), v.end(), cmp);
  for (i = 0; i < n; i++) {
    cout << v[i];
  }
  return 0;
}
