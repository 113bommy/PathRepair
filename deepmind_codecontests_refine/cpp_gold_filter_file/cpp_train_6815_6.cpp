#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1000006;
string s;
int a, b;
int moduleL[kMaxN], moduleR[kMaxN], pot[kMaxN];
int main() {
  cin >> s;
  cin >> a >> b;
  int n = s.size();
  moduleL[0] = (s[0] - '0') % a;
  for (int i = 1; i < n; ++i) {
    moduleL[i] = (1LL * moduleL[i - 1] * 10 + (s[i] - '0')) % a;
  }
  pot[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    pot[i] = (1LL * pot[i + 1] * 10) % b;
  }
  moduleR[n - 1] = (s[n - 1] - '0') % b;
  for (int i = n - 2; i >= 0; --i) {
    moduleR[i] = (1LL * moduleR[i + 1] + (s[i] - '0') * pot[i]) % b;
  }
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0') continue;
    if (moduleL[i - 1] == 0 && moduleR[i] == 0) {
      puts("YES");
      cout << s.substr(0, i) << "\n" << s.substr(i) << endl;
      return 0;
    }
  }
  puts("NO");
}
