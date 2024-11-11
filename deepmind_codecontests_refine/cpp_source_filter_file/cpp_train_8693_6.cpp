#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100050;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int BIT[NMAX];
void update(int first, int v) {
  for (int i = first; i <= NMAX; i += (i & -i)) BIT[i] += v;
}
long long get(int first) {
  long long res = 0;
  for (int i = first; i > 0; i -= (i & -i)) res += BIT[i];
  return res;
}
long long query(int l, int r) { return get(r) - get(l - 1); }
struct triple {
  long long c, l, r;
};
struct event {
  long long second, first, t;
};
bool cmp_triple(triple l, triple r) {
  return (l.c < r.c || (l.c == r.c && l.l < r.l) ||
          (l.c == r.c && l.l == r.l && l.r < r.r));
}
bool cmp_event(event l, event r) {
  return (l.second < r.second || (l.second == r.second && l.first < r.first) ||
          (l.second == r.second && l.first == r.first && l.t < r.t));
}
int a, n;
vector<triple> H, V;
vector<event> E;
map<long long, long long> M;
long long x_1, x_2, y_1, y_2;
triple t;
event e;
void merge(vector<triple> &A) {
  if (A.size() == 0) return;
  sort(A.begin(), A.end(), cmp_triple);
  int last = 1;
  for (int i = 1; i < A.size(); ++i) {
    if (A[last - 1].c == A[i].c && A[last - 1].r >= A[i].l) {
      t.c = A[i].c;
      t.l = A[last - 1].l;
      t.r = max(A[i].r, A[last - 1].r);
      A[last - 1] = t;
    } else {
      A[last++] = A[i];
    }
  }
  A.resize(last);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    if (x_1 == x_2) {
      if (y_1 > y_2) swap(y_1, y_2);
      t.l = y_1;
      t.r = y_2;
      t.c = x_1;
      V.push_back(t);
    }
    if (y_1 == y_2) {
      if (x_1 > x_2) swap(x_1, x_2);
      t.l = x_1;
      t.r = x_2;
      t.c = y_1;
      H.push_back(t);
    }
    M[x_1];
    M[x_2];
  }
  merge(V);
  merge(H);
  int rs = 0;
  for (auto &i : V) {
    rs += (i.r - i.l + 1);
    e.second = i.l;
    e.first = i.c;
    e.t = 1;
    E.push_back(e);
    e.second = i.r + 1;
    e.first = i.c;
    e.t = -1;
    E.push_back(e);
  }
  sort(E.begin(), E.end(), cmp_event);
  int cnt = 1;
  for (auto i : M) {
    M[i.first] = cnt++;
  }
  int last = 0;
  for (auto &i : H) {
    while (i.c >= E[last].second) {
      update(M[E[last].first], E[last].t);
      last++;
    }
    rs += i.r - i.l + 1 - query(M[i.l], M[i.r]);
  }
  cout << rs;
  return 0;
}
