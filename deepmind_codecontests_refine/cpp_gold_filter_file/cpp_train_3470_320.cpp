#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
long long n, a, b, tmp = 0, x = 0, y, c;
vector<pair<int, int> > vp;
bool first, firs, g, prev;
char ch;
vector<char> used;
vector<int> v;
string second, t;
char d[10];
map<string, long long> ma;
bool cmpvp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first < p2.first) return 1;
  if (p1.first == p2.first)
    if (p1.second < p2.second) return 1;
  return 0;
}
int main() {
  cin >> a;
  if (a == 1) cout << 2 << endl;
  if (a == 2) cout << 3 << endl;
  if (a == 3) cout << 1 << endl;
  if (a == 4) cout << 2 << endl;
  if (a == 5) cout << 1 << endl;
  return 0;
}
