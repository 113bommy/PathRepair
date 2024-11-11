#include <bits/stdc++.h>
using namespace std;
template <class T>
void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
static void redirect(int argc, const char **argv) {
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
}
int main(int argc, const char **argv) {
  redirect(argc, argv);
  long long N, M;
  string x, y;
  cin >> N >> M >> x >> y;
  long long lx = x.size(), ly = y.size();
  long long L = lx * N;
  long long g = gcd(lx, ly);
  long long minL = lx * (ly / g);
  long long ans = 0;
  for (int p = 0; p < g; p++) {
    long long freq1[26] = {}, freq2[26] = {};
    for (int i = p; i < lx; i += g) freq1[x[i] - 'a']++;
    for (int i = p; i < ly; i += g) freq2[y[i] - 'a']++;
    long long h = 0;
    for (int i = 0; i < 26; i++) h += freq1[i] * freq2[i];
    ans += h;
  }
  ans *= L / minL;
  ans = L - ans;
  cout << ans << '\n';
  return 0;
}
