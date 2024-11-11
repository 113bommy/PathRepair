#include <bits/stdc++.h>
using namespace std;
int f(int n) {
  int ans = 1;
  while (n != 0) {
    int x = n % 10;
    if (x != 0) ans = ans * x;
    n = n / 10;
  }
  return ans;
}
int g(int n, vector<int> &memoize) {
  if (memoize[n] != -1) return memoize[n];
  if (n < 10)
    return n;
  else {
    memoize[n] = g(f(n), memoize);
    return memoize[n];
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> memoize(1000001, -1);
  for (int i = 1; i <= 9; i++) memoize[i] = i;
  vector<vector<int> > matrix(1000001, vector<int>(11, 0));
  vector<int> accumulate(11, 0);
  for (int i = 1; i <= 1000000; i++) {
    g(i, memoize);
  }
  for (int i = 1; i <= 100000; i++) {
    int temp = memoize[i];
    int x = accumulate[temp];
    accumulate[temp] = x + 1;
    matrix[i] = accumulate;
  }
  for (int i = 1; i <= n; i++) {
    int a, b, k;
    cin >> a >> b >> k;
    int count = 0;
    count = (matrix[b][k] - matrix[a - 1][k]);
    cout << count << endl;
  }
  return 0;
}
