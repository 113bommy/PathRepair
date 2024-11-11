#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-13;
int in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
int N, K, H;
int m[101000];
pair<int, pair<int, int> > l[101000];
bool can(double T) {
  int cont = K;
  for (int i = 0; i < N; i++) {
    if (!(cont * double(H) > T * (l[i].second.first))) cont--;
    if (cont == 0) return true;
  }
  return false;
}
void show(double T) {
  vector<int> res;
  long long cont = K;
  for (int i = 0; i < N; i++) {
    if (!(cont * double(H) > T * (l[i].second.first))) {
      cont--;
      res.push_back((l[i].second.second) + 1);
    }
    if (cont == 0) break;
  }
  reverse((res).begin(), (res).end());
  for (int i = 0; i < res.size(); i++) {
    if (i) putchar(' ');
    printf("%d", res[i]);
  }
  puts("");
}
void solve() {
  N = in();
  K = in();
  H = in();
  for (int i = 0; i < N; i++) {
    m[i] = in();
  }
  int v;
  for (int i = 0; i < N; i++) {
    v = in();
    l[i] = make_pair(m[i], pair<int, int>(v, i));
  }
  sort(l, l + N);
  reverse(l, l + N);
  double inf = 0;
  double sup = 1001001001;
  double mid;
  for (int i = 0; i < 50; i++) {
    mid = (inf + sup) / 2;
    if (can(mid)) {
      sup = mid;
    } else {
      inf = mid;
    }
  }
  show(sup);
}
int main() {
  solve();
  return 0;
}
