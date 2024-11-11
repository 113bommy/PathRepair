#include <bits/stdc++.h>
using namespace std;
template <class T>
void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
static void redirect(int argc, const char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (argc > 1) {
    static filebuf f;
    f.open(argv[1], ios::in);
    cin.rdbuf(&f);
    if (!cin) {
      cerr << "Failed to open '" << argv[1] << "'" << endl;
      exit(1);
    }
  }
  if (argc > 2) {
    static filebuf f;
    f.open(argv[2], ios::out | ios::trunc);
    cout.rdbuf(&f);
    if (!cout) {
      cerr << "Failed to open '" << argv[2] << "'" << endl;
    }
  }
  cin.exceptions(ios::failbit);
}
struct ant {
  int id;
  long long s;
  long long stop;
  char d;
};
static long long mod(long long a, long long M) {
  a %= M;
  if (a < 0) a += M;
  return a;
}
static long long passes(const ant &a, const ant &b, long long M, long long T) {
  if (a.d == b.d) return 0;
  if (a.d == 'L') return mod(-passes(b, a, M, T), M);
  long long x = mod(b.s - a.s, M) / 2;
  if (T <= x)
    return 0;
  else
    return (T - x - 1) / (M / 2) + 1;
}
static void solve() {
  int N;
  long long M, T;
  cin >> N >> M >> T;
  M *= 6;
  T = T * 6 - 1;
  vector<ant> ants(N);
  for (int i = 0; i < N; i++) {
    cin >> ants[i].s >> ants[i].d;
    ants[i].s--;
    ants[i].s *= 6;
    ants[i].id = i;
  }
  sort(begin(ants), end(ants),
       [](const ant &a, const ant &b) { return a.s < b.s; });
  int pass = 0;
  vector<long long> fin(N);
  for (int i = 0; i < N; i++) {
    pass = mod(pass + passes(ants[0], ants[i], M, T), M);
    ants[i].stop = mod(ants[i].s + (ants[i].d == 'R' ? T : -T), M);
    fin[i] = ants[i].stop;
  }
  sort(begin(fin), end(fin));
  int pend = find(begin(fin), end(fin), ants[0].stop) - fin.begin();
  assert(pend < N);
  int add = mod(pend - pass, N);
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    long long pos = fin[(i + add) % N];
    ans[ants[i].id] = (pos + 1) % M / 6;
  }
  for (int i = 0; i < N; i++) cout << ans[i] + 1 << ' ';
  cout << '\n';
}
int main(int argc, const char **argv) {
  redirect(argc, argv);
  solve();
  return 0;
}
