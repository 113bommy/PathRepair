#include <bits/stdc++.h>
using namespace std;
long long mx = -1e9, mn = 1e9 + 5;
long long T, n, m, k, a[200][200], b, c, d, ans, l, r, sum, mid, coin, z, x, y,
    cnt, pos, number, check;
vector<long long> v, v1;
map<long long, long long> mp, mm;
map<long long, long long>::iterator it;
pair<long long, long long> p[100005];
queue<long long> q;
priority_queue<long long> pq;
char ch;
int main() {
  cin >> n >> k;
  if ((n - 1) * n / 2 <= k) {
    cout << "no solution";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cout << 0 << " " << i - 1 << endl;
  }
}
