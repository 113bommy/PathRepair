#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
pair<int, int> memo[1000000][20];
int is[1000000][20];
pair<int, int> recursive(int s, int a) {
  if (a == 1)
    return {((arr[s] + arr[s + 1]) >= 10), (arr[s] + arr[s + 1]) % 10};
  if (is[s][a]) return memo[s][a];
  int hi2 =
      recursive(s, a - 1).second + recursive(s + (1 << (a - 1)), a - 1).second;
  int hi1 = (hi2 >= 10) + recursive(s, a - 1).first +
            recursive(s + (1 << (a - 1)), a - 1).first;
  hi2 %= 10;
  is[s][a] = true;
  return memo[s][a] = {hi1, hi2};
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int asdf = b - a + 1;
    asdf = log2(asdf);
    if (asdf == 0)
      cout << 0 << '\n';
    else
      cout << recursive(a - 1, asdf).first << '\n';
  }
  return 0;
}
