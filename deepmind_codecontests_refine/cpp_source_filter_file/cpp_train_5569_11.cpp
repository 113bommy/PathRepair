#include <bits/stdc++.h>
using std::vector;
long long fib[105];
void init() {
  fib[1] = fib[2] = 1;
  for (int i = 3; i <= 100; ++i) fib[i] = fib[i - 1] + fib[i - 2];
}
vector<int> work(int n, int k) {
  vector<int> ans;
  if (n == 1)
    ans.push_back(1);
  else if (n == 2) {
    if (k == 1)
      ans.push_back(1), ans.push_back(2);
    else
      ans.push_back(2), ans.push_back(1);
  } else {
    if (k <= fib[n]) {
      ans = work(n - 1, k);
      for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
        (*it)++;
      ans.insert(ans.begin(), 1);
    } else {
      ans = work(n - 2, k - fib[n]);
      for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
        (*it) += 2;
      ans.insert(ans.begin(), 1);
      ans.insert(ans.begin(), 2);
    }
  }
  return ans;
}
int main() {
  init();
  int n;
  long long k;
  scanf("%d%I64d", &n, &k);
  vector<int> ans = work(n, k);
  for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    printf("%d%c", *it, it == ans.end() - 1 ? '\n' : ' ');
}
