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
struct student {
  int a;
  int id;
  bool operator<(const student &other) const { return a > other.a; };
};
static void solve() {
  int N;
  cin >> N;
  vector<student> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i].a;
    s[i].id = i;
  }
  sort(begin(s), end(s));
  vector<vector<pair<int, int>>> gaps(1);
  gaps[0].resize(N + 1);
  for (int i = 0; i <= N; i++)
    gaps[0][i] = pair<int, int>(s[max(0, i - 1)].a - (i == N ? 0 : s[i].a), i);
  int p = 1;
  while (p <= N) {
    gaps.emplace_back(N + 1);
    const auto &pg = gaps[((long long)(gaps).size()) - 2];
    for (int i = 0; i <= N - p; i++) gaps.back()[i] = max(pg[i], pg[i + p]);
    for (int i = N - p + 1; i <= N; i++) gaps.back()[i] = pg[i];
    p *= 2;
  }
  array<int, 3> ans = {-1, -1, -1};
  array<int, 3> ans_cut = {-1, -1, -1};
  for (int a = 1; a < N - 1; a++)
    for (int b = a + 1; b < N; b++) {
      int A = a;
      int B = b - a;
      if (A > 2 * B || B > 2 * A) continue;
      int minC = max(1, (max(A, B) + 1) / 2);
      int maxC = min(2 * A, 2 * B);
      int minc = b + minC;
      int maxc = min(N, b + maxC);
      if (minc > maxc) continue;
      int d = maxc - minc + 1;
      int r = 0;
      while ((2 << r) < d) r++;
      pair<int, int> best = max(gaps[r][minc], gaps[r][maxc - (1 << r)]);
      array<int, 3> score = {s[a - 1].a - s[a].a, s[b - 1].a - s[b].a,
                             best.first};
      if (score > ans) {
        ans = score;
        ans_cut[0] = a;
        ans_cut[1] = b;
        ans_cut[2] = best.second;
      }
    }
  vector<int> dip(N, -1);
  for (int i = 0; i < ans_cut[0]; i++) dip[s[i].id] = 1;
  for (int i = ans_cut[0]; i < ans_cut[1]; i++) dip[s[i].id] = 2;
  for (int i = ans_cut[1]; i < ans_cut[2]; i++) dip[s[i].id] = 3;
  for (int v : dip) cout << v << ' ';
  cout << '\n';
}
int main(int argc, const char **argv) {
  redirect(argc, argv);
  solve();
  return 0;
}
