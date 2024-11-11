#include <bits/stdc++.h>
using namespace std;
map<string, int> p;
int n, maxn;
string s;
int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    p[s]++;
  }
  maxn = p[s] > maxn ? p[s] : maxn;
  cout << maxn << endl;
  return 0;
}
