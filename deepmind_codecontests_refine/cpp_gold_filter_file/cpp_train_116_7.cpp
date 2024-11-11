#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int N = 200001;
const int oo = 1e9;
const double pi = acos(-1);
int main() {
  int n;
  string s;
  cin >> n >> s;
  bool can = false;
  for (int i = 0; i < n - 1; ++i)
    if (s[i] > s[i + 1]) can = true;
  if (!can) {
    puts("NO");
    return 0;
  }
  int a, b;
  char c = 'a';
  for (int i = 0; i < n; ++i) {
    if (s[i] > c) {
      c = s[i];
      a = i;
    }
    if (s[i] < c) {
      b = i;
      break;
    }
  }
  puts("YES");
  cout << a + 1 << " " << b + 1 << endl;
  return 0;
}
