#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string str;
  cin >> str;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  char c = str[0];
  int res = 0;
  int p = 0;
  for (int i = 1; i < str.length(); ++i) {
    if (str[i] != c) {
      res++;
      c = str[i];
    }
    if (str[i] == str[i - 1]) {
      p++;
    }
  }
  if (res >= 1) res++;
  if (p == 1) {
    if (res == 0) {
      res++;
    }
    res++;
  } else if (p >= 2) {
    if (res == 0) {
      res++;
    }
    res += 2;
  }
  cout << res << endl;
  return 0;
}
