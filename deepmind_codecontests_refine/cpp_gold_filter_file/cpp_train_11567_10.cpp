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
}
static long long gethi(int q, long long lo) {
  if (q == 0)
    return lo - 1;
  else if (q == 1) {
    return lo + min(lo, 10000LL) - 1;
  } else if (lo >= 10000) {
    long long c = 0;
    for (int i = 0; i < q; i++) c = c * 10001LL + 10000;
    return c + lo - 1;
  } else {
    int k = min(lo, 10000LL);
    for (int i = 0; i <= k; i++) {
      long long h = gethi(q - 1, lo);
      lo = h + 2;
    }
    return lo - 2;
  }
}
int main(int argc, const char **argv) {
  redirect(argc, argv);
  int q = 5;
  long long lo = 1;
  const long long M = 10004205361450474;
  long long hi = M;
  cerr << gethi(5, 1) << '\n';
  while (true) {
    vector<long long> guess;
    int k = min(lo, 10000LL);
    long long s = lo;
    for (int i = 0; i < k; i++) {
      long long h = gethi(q - 1, s) + 1;
      if (h > M) break;
      guess.push_back(h);
      s = h + 1;
    }
    k = ((long long)(guess).size());
    cout << k;
    for (long long v : guess) cout << ' ' << v;
    cout << endl;
    int ret;
    cin >> ret;
    if (ret < 0) break;
    if (ret > 0) lo = guess[ret - 1] + 1;
    if (ret < k) hi = guess[ret] - 1;
    q--;
  }
  return 0;
}
