#include <bits/stdc++.h>
const long long INF = (1e9 + 12312), MOD = 1e9 + 7;
const long double EPS = 0.0000000001;
using namespace std;
bool ask(long long first, long long second) {
  cout << first << " " << second << endl;
  string s;
  cin >> s;
  if (s == "Bad") {
    exit(1);
  }
  return s == "Yes";
}
signed main() {
  ios_base::sync_with_stdio(false);
  srand(time(0));
  long long n, k;
  cin >> n >> k;
  long long now = 0;
  long long first = 1, second = n;
  long long lastl = 1, lastr = n;
  for (int i = 0; i < 4500; i++) {
    if (now >= 7) {
      first = max(lastl - 8 * k, 1LL);
      second = min(lastr + 8 * k, n);
      lastl = -1;
      now = 0;
    }
    long long askl = first, askr = second;
    if (second - first == 0) {
      if (ask(first, first)) {
        return 0;
      }
      first = 1, second = n;
      continue;
    }
    if (second - first + 1 <= 30) {
      if (lastl == -1) {
        lastr = second;
        lastl = first;
      }
      now++;
      long long askl = first + rand() % (second - first + 1);
      if (ask(askl, askl)) {
        return 0;
      }
      continue;
    } else {
      now = 0;
      lastl = -1;
      lastr = -1;
      if (rand() % 2) {
        askl = first + (second - first + 1) / 2;
      } else {
        askr = second - (second - first + 1) / 2;
      }
    }
    if (ask(askl, askr)) {
      first = max(askl - k, 1LL);
      second = min(askr + k, n);
    } else {
      if (askl != first) {
        first -= k;
        first = max(first, 1LL);
        second = min(askl + k, n);
      } else {
        first = max(askr - k, 1LL);
        second += k;
        second = min(second, n);
      }
    }
  }
  return 0;
}
