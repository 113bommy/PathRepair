#include <bits/stdc++.h>
using namespace std;
vector<long long> invi(long long n) {
  int x;
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  return a;
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) solve();
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> jobcho = invi(n);
  vector<long long> time = invi(n);
  vector<long long> ind;
  vector<long long> task;
  for (long long i = 0; i < k; i++) {
    task.push_back(0);
    ind.push_back(n + 1);
  }
  for (long long i = 0; i < n; i++) {
    if (task[jobcho[i] - 1] < time[i]) {
      task[jobcho[i] - 1] = time[i];
      ind[jobcho[i] - 1] = i;
    }
  }
  for (long long i = 0; i < k; i++) {
    if (ind[i] < (n + 1)) time[ind[i]] = 1e10;
  }
  long long jbleft = 0;
  for (long long i = 0; i < k; i++) {
    if (task[i] == 0) {
      jbleft++;
    }
  }
  sort(time.begin(), time.end());
  long long sum = 0;
  for (long long i = 0; i < jbleft; i++) {
    sum += time[i];
  }
  cout << sum << "\n";
}
