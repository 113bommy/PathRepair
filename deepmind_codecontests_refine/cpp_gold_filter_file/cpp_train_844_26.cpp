#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, m, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  string s = "abcd";
  string s2 = "";
  int n1 = n;
  while (n1 >= 4) n1 -= 4, s2 += s;
  cout << s2 << s.substr(0, n1) << endl;
  ;
}
