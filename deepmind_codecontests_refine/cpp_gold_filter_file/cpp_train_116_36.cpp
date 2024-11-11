#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long n, m, x, i, z, cnt, sum, rem, tre, ert, ans, used[N];
vector<long long> v, v1;
vector<pair<string, string> > p;
set<char> second;
string s, s1, s2, s3, s4;
map<string, long long> mp;
char g;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  for (long long i = 0; i < s.size() - 1; i++) {
    if (s[i] > s[i + 1]) {
      cout << "YES" << endl;
      cout << i + 1 << " " << i + 2;
      return 0;
    }
  }
  cout << "NO";
}
