#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long n, m, t;
long long ans[N];
pair<long long, pair<long long, long long> > a[N];
vector<long long> vR, vL;
long long get(long long l, long long r, vector<long long> &v) {
  return upper_bound(v.begin(), v.end(), r) -
         lower_bound(v.begin(), v.end(), l);
}
int main() {
  scanf("%lld %lld %lld", &n, &m, &t);
  t *= 2;
  long long cR = 0, cL = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    char c;
    scanf("%lld %c", &x, &c);
    x--;
    a[i] = {x, {c, i}};
    if (c == 'R') {
      vR.push_back(x - m);
      vR.push_back(x);
      vR.push_back(x + m);
      cR++;
    } else {
      vL.push_back(x - m);
      vL.push_back(x);
      vL.push_back(x + m);
      cL++;
    }
  }
  sort(vR.begin(), vR.end());
  sort(vL.begin(), vL.end());
  sort(a, a + n);
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < n; i++) {
    long long x = a[i].first;
    long long c = a[i].second.first;
    if (c == 'L') {
      long long end = (x + t) % m;
      long long full = t / m;
      long long rem = t % m;
      long long ind = i;
      ind -= full % n * cR % n;
      ind -= get(x - rem, x, vR);
      ind = (ind % n + n) % n;
      ans[a[ind].second.second] = end;
    }
  }
  for (int i = 0; i < n; i++) {
    long long x = a[i].first;
    long long c = a[i].second.first;
    if (c == 'R') {
      long long end = x;
      long long full = t / m;
      long long rem = t % m;
      long long ind = i;
      ind += full % n * cL % n;
      ind += get(x, x + rem, vL);
      ind = (ind % n + n) % n;
      ans[a[ind].second.second] = end;
    }
  }
  for (int i = 0; i < n; i++) assert(ans[i] != -1);
  t /= 2;
  for (int i = 0; i < n; i++) {
    ans[i] = (ans[i] + t) % m + 1;
    printf("%lld ", ans[i]);
  }
  puts("");
  return 0;
}
