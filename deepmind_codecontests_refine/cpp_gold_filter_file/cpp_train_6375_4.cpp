#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18 + 1;
const int NMAX = 3555;
const int AMAX = 205;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char invdir[]{'L', 'U', 'R', 'D'};
const char dir[]{'R', 'D', 'L', 'U'};
int n;
long long trip, str;
int freq[NMAX];
int atleast1[NMAX];
int bin[NMAX * NMAX];
int last_str;
vector<int> dtrip, dstr;
bool test(int a, int b) {
  memset(atleast1, 0, sizeof(atleast1));
  memset(freq, 0, sizeof(freq));
  freq[1] = a;
  freq[2] = b;
  if (dstr[1]) atleast1[3] = 1;
  for (int i = 3; i < n; ++i) {
    if (dtrip[i - 1] > 0) {
      freq[i] = bin[dtrip[i - 1]];
    } else {
      freq[i] = atleast1[i];
    }
    atleast1[i + 1] =
        (dstr[i - 1] > (1LL * (freq[i - 1] + 1) * (freq[i - 2] + 1)));
  }
  freq[n] = (dstr[(n - 1) - 1] - (freq[n - 2] + 1) * (freq[n - 3] + 1)) /
            (freq[n - 2] + 1);
  int c = freq[3];
  int d = freq[4];
  int e = freq[5];
  int b_formula = (dstr[2] - d * e) / (a + d + 1) - 1;
  bool q = (dstr[0] == b * c) && (dstr[1] == ((a + 1) * c + c * d));
  return ((b == b_formula) && q && (last_str == (b + 1) * (c + 1)));
}
int soln = 0;
vector<int> sol[10];
void solve() {
  cin >> n;
  for (int i = 1; i <= 250; ++i) {
    bin[i * (i - 1) / 2] = i;
  }
  cin >> trip >> str;
  int trip1, str1;
  for (int i = 1; i < n; ++i) {
    cout << "+ " << i << "\n";
    cout.flush();
    cin >> trip1 >> str1;
    int tripd = trip1 - trip;
    int strd = str1 - str;
    dtrip.push_back(tripd);
    dstr.push_back(strd);
    trip = trip1;
    str = str1;
  }
  int a = 0;
  cout << "+ " << 1 << "\n";
  cout.flush();
  cin >> trip1 >> str1;
  a = bin[(trip1 - trip)] - 1;
  last_str = str1 - str;
  for (int j = 0; j <= 1; ++j) {
    if (dtrip[1] > 0) j = bin[dtrip[1]];
    if (test(a, j)) {
      break;
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << freq[i] << " ";
  }
  cout << "\n";
  cout.flush();
}
int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);
  std::cout << std::setprecision(16) << fixed;
  int T = 1;
  int i = 1;
  while (T--) {
    solve();
    i++;
  }
  return 0;
}
