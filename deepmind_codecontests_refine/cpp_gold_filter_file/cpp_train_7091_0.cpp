#include <bits/stdc++.h>
using namespace std;
map<char, vector<int> > mm;
const int MAX1 = 27, MOD = 12345;
int A[MAX1];
long long n, m;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
struct node {
  char c;
  vector<int> vs;
  long long val;
  node(char a = 0, vector<int> b = vector<int>()) : c(a), vs(b) {}
  void cal() {
    val = vs[0];
    for (int i = 1; i < vs.size(); i++) {
      val = lcm(val, vs[i]);
    }
  }
  void print() {
    printf("char = %c\n", c);
    for (int i = 0; i < vs.size(); i++) {
      printf("(%d, %d)->", i, vs[i]);
    }
    printf("val = %lld\n", val);
  }
};
node ns[MAX1];
int nsn;
vector<int> track;
int stn;
struct sta {
  int id;
  vector<int> ss;
  vector<int> who;
  bool ok;
  sta(int a = 0, vector<int> b = vector<int>()) : id(a), ss(b){};
  void print() {
    printf("id = %d\n", id);
    for (int i = 0; i < ss.size(); i++) printf("%d ", ss[i]);
    printf("\n");
    for (int i = 0; i < who.size(); i++) printf("%d ", who[i]);
    printf("\n");
  }
  void check() {
    ok = 1;
    for (int i = 0; i < nsn; i++) {
      if (ss[i] == 0) continue;
      bool zok = 0;
      for (int j = 0; j < ns[i].vs.size(); j++) {
        int cz = ns[i].vs[j];
        if (ss[i] % cz == 0) {
          zok = 1;
          break;
        }
      }
      if (zok == 0) {
        ok = 0;
        break;
      }
    }
  }
};
sta sts[150];
int ini[150];
void sol1(int pos) {
  if (pos == nsn) {
    sts[stn] = {stn, track}, stn++;
    return;
  } else {
    for (int sel = 0; sel < ns[pos].val; sel++) {
      track[pos] = sel;
      sol1(pos + 1);
    }
  }
}
struct matrix {
  int zj[150][150], rn;
  matrix(int a = 0) : rn(a) {}
};
matrix operator*(const matrix &a, const matrix &b) {
  int n = a.rn;
  matrix ret;
  ret.rn = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ret.zj[i][j] = 0;
      for (int k = 0; k < n; k++) {
        ret.zj[i][j] = (ret.zj[i][j] + a.zj[i][k] * b.zj[k][j]) % MOD;
      }
    }
  }
  return ret;
}
matrix pows(matrix a, long long pp) {
  if (pp == 1)
    return a;
  else {
    matrix tmp = pows(a, pp / 2);
    if (pp % 2 == 0)
      return tmp * tmp;
    else
      return tmp * tmp * a;
  }
}
int main() {
  scanf("%lld%lld\n", &n, &m);
  for (int i = 0; i < m; i++) {
    char c;
    int t;
    scanf("%c %d\n", &c, &t);
    mm[c].push_back(t);
  }
  nsn = 0;
  for (auto ele : mm) {
    ns[nsn++] = {ele.first, ele.second};
    ns[nsn - 1].cal();
  }
  track.resize(nsn);
  stn = 0;
  sol1(0);
  for (int i = 0; i < stn; i++) {
    for (int j = 0; j < nsn; j++) {
      int bb = ns[j].val;
      auto &ss = sts[i].ss;
      if (ss[j] + 1 < bb) {
        vector<int> tmp = ss;
        tmp[j]++;
        int vh = -1;
        for (int k = 0; k < stn; k++) {
          if (sts[k].ss == tmp) {
            vh = k;
            break;
          }
        }
        assert(vh != -1);
        sts[i].who.push_back(vh);
      } else {
        vector<int> tmp = ss;
        tmp[j] = 0;
        int vh = -1;
        for (int k = 0; k < stn; k++) {
          if (sts[k].ss == tmp) {
            vh = k;
            break;
          }
        }
        assert(vh != -1);
        sts[i].who.push_back(vh);
      }
    }
  }
  matrix ori;
  ori.rn = stn;
  memset(ori.zj, 0, sizeof(ori.zj));
  for (int i = 0; i < stn; i++) {
    for (int j = 0; j < sts[i].who.size(); j++) {
      int w = sts[i].who[j];
      ori.zj[i][w]++;
    }
  }
  memset(ini, 0, sizeof(ini));
  ini[0] = 1;
  if (n == 0)
    printf("%d\n", 1);
  else {
    for (int i = 0; i < stn; i++) sts[i].check();
    matrix tmp = pows(ori, n);
    int ans[150];
    int n = stn;
    for (int col = 0; col < n; col++) {
      ans[col] = 0;
      for (int k = 0; k < n; k++) {
        ans[col] = (ans[col] + ini[k] * tmp.zj[k][col]) % MOD;
      }
    }
    int hh = 0;
    for (int i = 0; i < n; i++) {
      if (sts[i].ok) {
        hh = (hh + ans[i]) % MOD;
      }
    }
    printf("%d\n", hh);
  }
  return 0;
}
