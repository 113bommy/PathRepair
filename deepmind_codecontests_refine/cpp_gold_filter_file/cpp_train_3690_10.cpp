#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <class T>
string tos(T n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long powmod(long long a, long long p, long long m) {
  long long r = 1;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
int n, m;
struct node {
  int label;
  int w;
  bool operator<(const node& other) const { return w > other.w; }
};
int w[(int)1e5 + 5];
node v[(int)1e5 + 5];
bool used[(int)1e5 + 5];
vector<int> L[(int)1e5 + 5];
class SetUnion {
 public:
  vector<int> p;
  vector<int> size;
  int n;
  SetUnion(int _n) : n(_n) {
    p = vector<int>(n, -1);
    size = vector<int>(n, 1);
  }
  int Find(int x) {
    if (p[x] == -1)
      return x;
    else
      return p[x] = Find(p[x]);
  }
  void Union(int s1, int s2) {
    int r1, r2;
    r1 = Find(s1);
    r2 = Find(s2);
    if (r1 == r2) return;
    if (size[r1] >= size[r2]) {
      size[r1] = size[r1] + size[r2];
      p[r2] = r1;
    } else {
      size[r2] = size[r1] + size[r2];
      p[r1] = r2;
    }
  }
};
int main(int argc, char* argv[]) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    v[i].w = w[i];
    v[i].label = i;
  }
  while (m--) {
    int(x), (y);
    scanf("%d %d", &(x), &(y));
    ;
    x--, y--;
    L[x].push_back(y);
    L[y].push_back(x);
  }
  sort(v, v + n);
  SetUnion SU(n);
  memset(used, false, sizeof(used));
  long long cost = 0;
  for (int k = 0; k < n; k++) {
    int x = v[k].label;
    used[x] = true;
    long long sum = 0;
    long long cnt = 0;
    for (int i = 0; i < L[x].size(); i++) {
      int y = L[x][i];
      int fay = SU.Find(y);
      int fax = SU.Find(x);
      if (fax != fay && used[fay]) {
        int size = SU.size[fay];
        SU.Union(x, y);
        cnt += size * (sum + 1);
        sum += size;
      }
    }
    cost += cnt * v[k].w;
  }
  printf("%.6lf\n", ((double)cost) * 2 / n / (n - 1));
  return EXIT_SUCCESS;
}
