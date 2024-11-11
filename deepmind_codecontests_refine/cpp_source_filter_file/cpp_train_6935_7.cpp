#include <bits/stdc++.h>
using namespace std;
long long mx = -1e9, mn = 1e9 + 5;
long long T, n, m, k, ans, a[510][510], b, c, l, r, sum, mid, coin, cnt, pos,
    number, x, y, z;
vector<long long> v, v1;
map<long long, long long> mp, mm;
map<long long, long long>::iterator it;
pair<long long, long long> p[100005];
queue<long long> q;
priority_queue<long long> pq;
double d[10];
int main() {
  long long h, s, t1, t2;
  cin >> h >> m >> s >> t1 >> t2;
  h *= 5;
  t1 *= 5;
  t2 *= 5;
  mp[h]++;
  mp[t1]++;
  mp[t2]++;
  if (t1 > t2) {
    swap(t2, t1);
  }
  for (int i = t1; i < t2; i++) {
    ans += mp[i];
  }
  if (ans == 0 || ans == 3) {
    cout << "YES";
  } else
    cout << "NO";
}
