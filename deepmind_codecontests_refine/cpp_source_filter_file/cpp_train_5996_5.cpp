#include <bits/stdc++.h>
using namespace std;
long long n, q, ans, tst, i, a, k, cont, j, t, d, b, sum, p, m, l;
vector<int> v;
vector<long long> v2;
set<long long> st;
string s;
char c;
map<string, int> mp;
bool ah = false;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    v.push_back(i);
  }
  for (i = 0; i < k; i++) {
    cin >> a;
    v2.push_back(a);
  }
  d = k;
  for (i = 0; i < d; i++) {
    l = (l + v2[i] + 1) % v.size();
    cout << v[l - 1] << "  ";
    v.erase(v.begin() + l);
  }
}
