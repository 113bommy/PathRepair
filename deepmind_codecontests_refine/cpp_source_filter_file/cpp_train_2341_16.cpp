#include <bits/stdc++.h>
using namespace std;
int N, L;
vector<pair<pair<long long, long long>, pair<long long, long long> > > v;
long long MAXSUM, MINSUM, MAXDIF, MINDIF;
long long X, Y;
bool failed;
long long parity(long long x) {
  if (x < 0) x = -x;
  return x % 2;
}
long long ceil_div(long long x, long long y);
long long floor_div(long long x, long long y) {
  if (x >= 0) return x / y;
  return -ceil_div(-x, y);
}
long long ceil_div(long long x, long long y) {
  if (x >= 0) return (x + y - 1) / y;
  return -floor_div(-x, y);
}
void check(long long t, long long cycle, long long x, long long y) {
  if (cycle == 0) {
    if (((x) > 0 ? (x) : -(x)) + ((y) > 0 ? (y) : -(y)) > t) failed = true;
    return;
  }
  if (cycle < 0) {
    cycle = -cycle;
    x = -x;
    y = -y;
  }
  MAXSUM = min(MAXSUM, floor_div(x + y + t, cycle));
  MINSUM = max(MINSUM, ceil_div(x + y - t, cycle));
  MAXDIF = min(MAXDIF, floor_div(x - y + t, cycle));
  MINDIF = max(MINDIF, ceil_div(x - y - t, cycle));
}
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
string ds = "RLUD";
map<int, pair<int, int> > mp;
vector<pair<int, pair<int, int> > > vv;
void construct(void) {
  int i, j;
  string ans;
  for (__typeof((mp).begin()) itr = (mp).begin(); itr != (mp).end(); itr++)
    vv.push_back(*itr);
  for ((i) = 0; (i) < (int)(vv.size() - 1); (i)++) {
    int t = vv[i + 1].first - vv[i].first;
    int x = vv[i + 1].second.first - vv[i].second.first;
    int y = vv[i + 1].second.second - vv[i].second.second;
    while (t > 0) {
      for ((j) = 0; (j) < (int)(4); (j)++)
        if (((x - dx[j]) > 0 ? (x - dx[j]) : -(x - dx[j])) +
                ((y - dy[j]) > 0 ? (y - dy[j]) : -(y - dy[j])) <=
            t - 1) {
          t--;
          x -= dx[j];
          y -= dy[j];
          ans += ds[j];
          break;
        }
    }
  }
  printf("%s\n", ans.c_str());
}
long long input(void) {
  long long x;
  scanf("%I64d", &x);
  return x;
}
int main(void) {
  int i;
  cin >> N >> L;
  failed = false;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    long long t = input();
    long long x = input();
    long long y = input();
    long long tmp = x + y + t;
    if (tmp < 0) tmp = -tmp;
    if (tmp % 2 != 0) {
      cout << "NO" << endl;
      return 0;
    }
    v.push_back(make_pair(make_pair(t % L, t), make_pair(x, y)));
  }
  sort(v.begin(), v.end());
  MAXSUM = MAXDIF = L;
  MINSUM = MINDIF = -L;
  check(v[0].first.first, v[0].first.second / L, v[0].second.first,
        v[0].second.second);
  check(L - v[N - 1].first.first, 1 - v[N - 1].first.second / L,
        v[N - 1].second.first, v[N - 1].second.second);
  for ((i) = 0; (i) < (int)(N - 1); (i)++)
    check(v[i + 1].first.first - v[i].first.first,
          v[i + 1].first.second / L - v[i].first.second / L,
          v[i + 1].second.first - v[i].second.first,
          v[i + 1].second.second - v[i].second.second);
  if (parity(MAXSUM) != L % 2) MAXSUM--;
  if (parity(MINSUM) != L % 2) MINSUM++;
  if (parity(MAXDIF) != L % 2) MAXDIF--;
  if (parity(MINDIF) != L % 2) MINDIF++;
  if (MAXSUM < MINSUM || MAXDIF < MINDIF) failed = true;
  if (failed) {
    cout << "NO" << endl;
    return 0;
  }
  int CX = (MAXSUM + MAXDIF) / 2;
  int CY = (MAXSUM - MAXDIF) / 2;
  mp[0] = make_pair(0, 0);
  mp[L] = make_pair(CX, CY);
  for ((i) = 0; (i) < (int)(N); (i)++) {
    long long t = v[i].first.second;
    long long x = v[i].second.first;
    long long y = v[i].second.second;
    long long cycle = t / L;
    t -= cycle * L;
    x -= cycle * CX;
    y -= cycle * CY;
    mp[(int)t] = make_pair((int)x, (int)y);
  }
  construct();
  return 0;
}
