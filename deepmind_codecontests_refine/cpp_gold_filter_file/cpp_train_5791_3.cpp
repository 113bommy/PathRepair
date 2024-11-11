#include <bits/stdc++.h>
using namespace std;
const long long P = 257, M = 1000000007;
long long p[25];
void GO() {
  p[0] = 1;
  for (long long i = 1; i <= 20; i++) {
    p[i] = (p[i - 1] * P) % M;
  }
}
struct z {
  long long _ind;
  string s;
  bool flag;
};
map<long long, z> a[12];
string ans[80000];
struct nomer {
  string s;
  long long h[15], _ind;
  void StartHash() {
    for (long long i = 1; i <= 9; i++) h[i] = (h[i - 1] * P + s[i - 1]) % M;
  }
  long long FindHash(long long l, long long r) {
    return (h[r] - h[l] * p[r - l] + M * M) % M;
  }
  void StartVek() {
    for (long long i = 1; i <= 9; i++) {
      for (long long j = 0; j < 9; j++) {
        if (j + i > 9) continue;
        string podstr = "";
        for (long long x = j; x < i + j; x++) podstr += s[x];
        if (a[(i + j) - j].count(FindHash(j, i + j))) {
          if (a[(i + j) - j][FindHash(j, i + j)]._ind != _ind)
            a[(i + j) - j][FindHash(j, i + j)].flag = false;
        } else {
          a[((i + j) - j)][FindHash(j, i + j)]._ind = _ind;
          a[((i + j) - j)][FindHash(j, i + j)].s = podstr;
          a[((i + j) - j)][FindHash(j, i + j)].flag = true;
        }
      }
    }
  }
};
nomer a1[80000];
int main() {
  ios_base::sync_with_stdio(0);
  GO();
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a1[i].s;
    a1[i]._ind = i;
    a1[i].StartHash();
    a1[i].StartVek();
  }
  for (long long i = 1; i <= 9; i++) {
    for (auto it = a[i].begin(); it != a[i].end(); it++) {
      pair<long long, z> vr = *it;
      if (vr.second.flag && ans[vr.second._ind] == "") {
        ans[vr.second._ind] = vr.second.s;
      }
    }
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << endl;
}
