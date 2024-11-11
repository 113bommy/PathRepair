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
static void solve() {
  int N;
  cin >> N;
  map<int, int> prefs, suffs;
  for (int i = 0; i < N; i++) {
    string s;
    int lvl = 0;
    int min_lvl = 0;
    cin >> s;
    for (char c : s) {
      if (c == '(')
        lvl++;
      else {
        lvl--;
        min_lvl = min(min_lvl, lvl);
      }
    }
    if (lvl >= 0 && min_lvl == 0) prefs[lvl]++;
    if (lvl <= 0 && min_lvl >= lvl) suffs[-lvl]++;
  }
  long long ans = 0;
  for (const auto &e : prefs)
    if (suffs.count(e.first)) ans += e.second * suffs[e.first];
  cout << ans << '\n';
}
int main(int argc, const char **argv) {
  redirect(argc, argv);
  solve();
  return 0;
}
