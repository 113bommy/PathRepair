#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
vector<int> v, v1, v2, r, l, v3;
long long n, x, cnt, pr = 1, i, c, ans, d, mn, y, mx, m, zm, sum, z;
string s, s1, s2, s3, ss, s4, s5;
set<int> st;
set<int> st1;
map<int, int> mp, mpp, mppp;
bool tr = 0, t = 0;
long long used[1000001];
vector<int> g[N];
vector<pair<int, int>> vp;
char a, b;
void print(vector<int>& v) {
  for (auto c : v) cout << c << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n % 2 == 0)
    cout << "hite\n1 2";
  else
    cout << "black";
}
