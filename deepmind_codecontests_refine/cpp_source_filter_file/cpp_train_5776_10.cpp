#include <bits/stdc++.h>
template <typename T>
void xchg(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}
using namespace std;
void _main();
int main() {
  _main();
  return 0;
}
int isVowel(char c) {
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}
const int MAX_SIZE = 500000;
int vowel[MAX_SIZE];
int N;
long double score[MAX_SIZE];
long double cScore[MAX_SIZE];
void _main() {
  string s;
  int i;
  cin >> s;
  N = s.length();
  for (i = 0; i < (N); ++i) {
    vowel[i] = isVowel(s[i]);
  }
  long double tmp;
  for (i = (1); i < (N + 1); ++i) {
    tmp = 1.0 / i;
    score[i] = score[i - 1] + tmp;
    cScore[i] = cScore[i - 1] + (N - i + 1) * tmp;
  }
  long double ans = 0;
  for (i = (0); i < (N); ++i) {
    if (vowel[i]) {
      int p = i + 1;
      if (p > (N >> 1)) p = N - i;
      ans += p + cScore[N] - cScore[N - p] + p * (score[N - p] - score[p]);
    }
  }
  printf("%0.6Lf\n", ans);
}
