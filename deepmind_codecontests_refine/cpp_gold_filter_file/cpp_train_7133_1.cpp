#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long a[N];
bool cmp(string a, string b) { return (a + b < b + a); }
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<string> v;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end(), cmp);
  for (auto i : v) cout << i;
  return 0;
}
