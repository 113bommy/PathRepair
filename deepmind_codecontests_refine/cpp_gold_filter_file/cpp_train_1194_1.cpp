#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int pow(int a, int n, int m) {
  int acc = 1;
  while (n > 0) {
    if (n % 2 == 0) {
      a = ((long long)a * a) % m;
      n /= 2;
    } else {
      acc = ((long long)acc * a) % m;
      n--;
    }
  }
  return acc;
}
string shift(const string& s, int k) {
  int mod = s.size();
  string ret(mod, 0);
  for (int i = 0; i < mod; i++) {
    ret[i] = s[(i + k) % mod];
  }
  return ret;
}
int cnt[4];
int onto[256];
int n;
int main(int argc, char* argv[]) {
  cin >> n;
  string s;
  cin >> s;
  onto['A'] = 0;
  onto['C'] = 1;
  onto['G'] = 2;
  onto['T'] = 3;
  for (int i = 0; i < n; i++) {
    cnt[onto[s[i]]]++;
  }
  int max = -1;
  int S = 0;
  for (int i = 0; i < 4; i++) {
    if (cnt[i] > max) {
      max = cnt[i];
      S = 1;
    } else if (cnt[i] == max) {
      S++;
    }
  }
  printf("%d\n", pow(S, n, MOD));
  return 0;
}
