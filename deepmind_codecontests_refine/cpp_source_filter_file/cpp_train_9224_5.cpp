#include <bits/stdc++.h>
using namespace std;
ofstream fo("test.out");
ifstream fi("test.inp");
long long n, t;
string s;
map<string, int> rs;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (!rs[s])
      cout << "YES";
    else
      cout << "NO";
    rs[s]++;
  }
  return 0;
}
