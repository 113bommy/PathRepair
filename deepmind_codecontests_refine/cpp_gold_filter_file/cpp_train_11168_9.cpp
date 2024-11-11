#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n;
pair<int, int> a[N];
int val[N];
int ask(pair<int, int> a) {
  cout << "? " << a.first << ' ' << a.second << endl;
  int sum;
  cin >> sum;
  return sum;
}
void solve() {
  for (int i = (2); i <= (int)(n); i += (1)) {
    int sum = ask({i - 1, i});
    a[i].first = -a[i - 1].first;
    a[i].second = sum - a[i - 1].second;
  }
  int sumfs = 0, sumse = 0;
  for (int i = (1); i <= (int)(n); i += (1)) {
    sumfs += a[i].first;
    sumse += a[i].second;
  }
  int total = ask({1, n});
  val[1] = (total - sumse) / sumfs;
  for (int i = (2); i <= (int)(n); i += (1))
    val[i] = a[i].first * val[1] + a[i].second;
}
int main() {
  cin >> n;
  a[1] = {1, 0};
  if (n & 1)
    solve();
  else {
    n--;
    solve();
    n++;
    int lstsum = ask({n - 1, n});
    val[n] = lstsum - val[n - 1];
  }
  cout << "!";
  for (int i = (1); i <= (int)(n); i += (1)) cout << " " << val[i];
  cout << endl;
  return 0;
}
