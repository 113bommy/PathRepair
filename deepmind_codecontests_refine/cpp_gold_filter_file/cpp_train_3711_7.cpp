#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long inf = 1e17 + 7;
const long long logg = 62;
long long hi(long long a) {
  if (a == 1) {
    return 0;
  }
  return hi(a >> 1) + 1;
}
vector<long long> b[logg];
long long nxt[maxn];
long long xo[maxn];
long long joda[maxn];
long long cnt = 1;
void pri() {
  long long be = nxt[0];
  while (be != -1) {
    cout << joda[be] << ' ';
    be = nxt[be];
  }
  cout << endl;
  long long h = 0;
  be = nxt[0];
  while (be != -1) {
    h ^= joda[be];
    be = nxt[be];
  }
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long v;
    cin >> v;
    b[hi(v)].push_back(v);
  }
  nxt[0] = -1;
  xo[0] = 0;
  joda[0] = 0;
  for (long long i = logg - 1; i >= 0; i--) {
    long long be = 0;
    bool hal = 0;
    while (be != -1 && b[i].size()) {
      if ((((xo[be] >> i) ^ hal) & 1) == 0) {
        nxt[cnt] = nxt[be];
        nxt[be] = cnt;
        joda[cnt] = b[i].back();
        b[i].pop_back();
        be = cnt;
        cnt++;
        hal ^= 1;
      }
      be = nxt[be];
    }
    if (b[i].size()) {
      cout << "No";
      return 0;
    }
    be = 0;
    long long h = 0;
    while (be != -1) {
      h ^= joda[be];
      xo[be] = h;
      be = nxt[be];
    }
  }
  cout << "Yes\n";
  pri();
}
