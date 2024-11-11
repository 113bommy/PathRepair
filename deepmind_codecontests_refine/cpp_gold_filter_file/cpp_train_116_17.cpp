#include <bits/stdc++.h>
using namespace std;
const long long N = 4 * 10e5;
const long long MX = -1e9 - 3;
const long long MN = 1e9 + 3;
long long n, m, cnt, ans, x, a, b, mx = MX, mn = MN, c;
bool bl;
string str = "ACTG", s;
map<char, long long> mp;
vector<long long> v, q;
pair<char, long long> pr[N];
pair<long long, char> pr1[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  for (long long i = 0; i < s.size() - 1; i++) {
    if (s[i] > s[i + 1]) {
      cout << "YES\n" << i + 1 << " " << i + 2;
      return 0;
    }
  }
  cout << "NO";
}
