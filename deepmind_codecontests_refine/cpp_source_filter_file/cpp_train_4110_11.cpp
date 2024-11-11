#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp, pm;
vector<long long> v;
deque<long long> p;
long long a, b, c, d, e, cnt, ans, r, n;
long double q;
string g, h, w, o, z, m;
char t, y, u;
int main() {
  cout.tie(NULL);
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c >> d;
  cnt = max(3 * a / 10, a - a / 250 * c);
  ans = max(3 * b / 10, b - b / 250 * d);
  if (cnt > ans)
    cout << "Vasya";
  else if (cnt < ans)
    cout << "Misha";
  else
    cout << "Tie";
}
