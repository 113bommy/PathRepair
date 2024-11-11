#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
mt19937 gen(static_cast<unsigned int>(time(NULL)));
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string summa;
  bool overflow = false;
  const uint32_t K = 26;
  const uint32_t start = static_cast<uint32_t>('a');
  for (int i = n - 1; i >= 0; --i) {
    uint32_t a = static_cast<uint32_t>(s[i]) - start;
    uint32_t b = static_cast<uint32_t>(t[i]) - start;
    uint32_t tmp = a + b + (overflow ? 1 : 0);
    overflow = tmp >= K;
    summa += static_cast<char>(tmp - (tmp >= K ? K : 0) + start);
  }
  reverse((summa).begin(), (summa).end());
  string res;
  for (size_t i = 0; i < summa.size(); ++i) {
    uint32_t a = static_cast<uint32_t>(summa[i]) - start + (overflow ? K : 0);
    res += static_cast<char>(a / 2 + start);
    overflow = a % 2 == 1;
  }
  cout << res;
  return 0;
}
