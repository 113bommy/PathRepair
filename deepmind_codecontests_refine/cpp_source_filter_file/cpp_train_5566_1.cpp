#include <bits/stdc++.h>
using namespace std;
template <class t>
t mabs(t x) {
  return (x < 0) ? -x : x;
}
void pv(vector<long long> a) {
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}
long long add(long long a, long long b) {
  a += b;
  if (a > 1000000007) a -= 1000000007;
  return a;
}
void do_nothing() {}
void solve() {
  int n_, a, b, k;
  cin >> n_ >> a >> b >> k;
  int x, n;
  if (a < b) {
    x = b - a - 1;
    n = b - 1;
  } else {
    n = n_ - b;
    x = a - b - 1;
  }
  vector<long long> answers(n);
  vector<long long> answers2(n);
  for (int(i) = 0; (i) < (n); (i)++) answers[i] = 1;
  for (int(i___) = 0; (i___) < (k); (i___)++) {
    answers2[0] = 0;
    for (int j = (1); j < (int)(n); j++) {
      long long t = answers2[j - 1] + answers[j - 1] - answers[j];
      if (t < 0)
        t += 1000000007;
      else if (t > 1000000007)
        t -= 1000000007;
      for (int i = 2 * j - 1; i < min(n, 2 * j + 1); ++i) {
        t += answers[i];
        if (t > 1000000007) t -= 1000000007;
      }
      answers2[j] = t;
    }
    answers2.swap(answers);
  }
  cout << answers[x] << endl;
  return;
}
int main() {
  solve();
  return 0;
}
