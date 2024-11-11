#include <bits/stdc++.h>
using namespace std;
template <class T>
int chkmax(T& a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
int chkmin(T& a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class iterator>
void output(iterator begin, iterator end, ostream& out = cerr) {
  while (begin != end) {
    out << (*begin) << " ";
    begin++;
  }
  out << endl;
}
template <class T>
void output(T x, ostream& out = cerr) {
  output(x.begin(), x.end(), out);
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct event {
  int x, type, data;
};
bool operator<(event a, event b) {
  return make_pair(a.x, a.type) < make_pair(b.x, b.type);
}
const int INF = 1e9 + 228;
const int BLOCK = 30;
const int mx = 1e5 + 228;
int n, w, q, x[mx], ans[mx], ptr[mx];
vector<event> ev;
void read() {
  cin >> n >> w >> q;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
}
void build_ev() {
  for (int i = 0; i < n; ++i) {
    ptr[i] = i + 1;
    int low = x[i], high = x[i];
    for (int j = i + 1; j <= min(n - 1, i + BLOCK); ++j) {
      chkmin(low, x[j]);
      chkmax(high, x[j]);
      ev.push_back({high - low, 0, i});
    }
  }
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    ev.push_back({w - k, 1, i});
  }
  sort(ev.begin(), ev.end());
}
int link[mx], jumps[mx];
void increase_ptr(int pos) {
  ptr[pos]++;
  for (int i = pos; i >= max(0, pos - BLOCK + 1); --i) {
    int r = i + BLOCK;
    link[i] = i;
    jumps[i] = 0;
    while (ptr[link[i]] < r) {
      link[i] = ptr[link[i]];
      jumps[i]++;
    }
  }
}
const int lg = 20;
int sp_max[mx][lg], sp_min[mx][lg], pw2[mx];
void build_scp() {
  for (int i = 2; i <= n; ++i) {
    pw2[i] = pw2[i / 2] + 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    sp_min[i][0] = sp_max[i][0] = x[i];
    for (int it = 1; it < lg; ++it) {
      sp_min[i][it] = sp_min[i][it - 1];
      sp_max[i][it] = sp_max[i][it - 1];
      int i1 = i + (1 << (it - 1));
      if (i1 < n) {
        chkmin(sp_min[i][it], sp_min[i1][it - 1]);
        chkmax(sp_max[i][it], sp_max[i1][it - 1]);
      }
    }
  }
}
int get(int l, int r) {
  int deg = pw2[r - l + 1], r1 = r - (1 << deg) + 1;
  int res = max(sp_max[l][deg], sp_max[r1][deg]) -
            min(sp_min[l][deg], sp_min[r1][deg]);
  return res;
}
int find_next(int pos, int k) {
  int l = pos, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    int res = get(pos, mid + 1);
    if (res <= k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l + 1;
}
int query(int k) {
  int pos = 0, res = 0;
  while (pos < n) {
    res += jumps[pos];
    pos = link[pos];
    if (pos < n && link[pos] == pos) {
      res++;
      pos = find_next(pos, k);
    }
  }
  return res;
}
void process() {
  ptr[n] = INF;
  for (int i = 0; i < n; ++i) {
    link[i] = min(n, i + BLOCK);
    jumps[i] = link[i] - i;
  }
  for (auto e : ev) {
    if (e.type == 0) {
      increase_ptr(e.data);
    } else {
      int res = query(e.x);
      ans[e.data] = res - 1;
    }
  }
}
void print_ans() {
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}
signed main() {
  fast_io();
  read();
  build_ev();
  build_scp();
  process();
  print_ans();
}
