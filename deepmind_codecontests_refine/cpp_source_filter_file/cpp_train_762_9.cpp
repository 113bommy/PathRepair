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
static long long power2[1000001];
static vector<long long> ways(const string &s, char b, char w, int K) {
  int N = ((int)(s).size());
  vector<int> sumB(N + 1), sumX(N + 1), sumW(N + 1);
  vector<long long> ans(N + 1);
  vector<long long> asum(N + 1);
  for (int i = 1; i <= N; i++) {
    sumB[i] = sumB[i - 1];
    sumW[i] = sumW[i - 1];
    sumX[i] = sumX[i - 1];
    if (s[i - 1] == b)
      sumB[i]++;
    else if (s[i - 1] == w)
      sumW[i]++;
    else
      sumX[i]++;
    ans[i] = 0;
    if (i >= K) {
      if (sumW[i - K] == sumW[i]) {
        if (i == K)
          ans[i] = 1;
        else if (s[i - K - 1] != b) {
          ans[i] = (power2[sumX[i - K - 1]] - asum[i - K - 1]) % 1000000009;
        }
      }
      if (s[i - 1] == 'X')
        asum[i] = (asum[i - 1] * 2 + ans[i]) % 1000000009;
      else
        asum[i] = (asum[i - 1] + ans[i]) % 1000000009;
    }
  }
  return ans;
}
int main(int argc, const char **argv) {
  redirect(argc, argv);
  int N, K;
  string s;
  cin >> N >> K;
  cin >> s;
  power2[0] = 1;
  for (int i = 1; i <= N; i++) power2[i] = (power2[i - 1] * 2) % 1000000009;
  vector<long long> L = ways(s, 'B', 'W', K);
  reverse((s).begin(), (s).end());
  vector<long long> R = ways(s, 'W', 'B', K);
  reverse((s).begin(), (s).end());
  long long sumL = 0;
  long long ans = 0;
  for (int i = K; i + K <= N; i++) {
    if (s[i - 1] == 'X') sumL = (2 * sumL) % 1000000009;
    sumL = (sumL + L[i]) % 1000000009;
    ans = (ans + sumL * R[N - i]) % 1000000009;
  }
  if (ans < 0) ans += 1000000009;
  cout << ans << '\n';
  return 0;
}
