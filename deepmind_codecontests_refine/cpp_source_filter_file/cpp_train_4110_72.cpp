#include <bits/stdc++.h>
using namespace std;
string s, t, e;
long long n, m, cnt, ans, sum, x, y, b, w, h, k, p1, p2, t1, t2;
set<int> st;
vector<int> v;
char c;
bool o = false;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> p1 >> p2 >> t1 >> t2;
  x = max((30 * p1) / 10, p1 - (p1 / 250) * t1);
  y = max((30 * p2) / 10, p2 - (p2 / 250) * t2);
  if (x > y)
    cout << "Misha";
  else if (x < y)
    cout << "Vasya";
  else
    cout << "Tie";
}
