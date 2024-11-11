#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const long long inf = 1e18 + 5;
vector<long long> fib;
void precompute() {
  fib.push_back(1);
  fib.push_back(2);
  while (fib[fib.size() - 1] < inf) {
    int len = fib.size();
    fib.push_back(fib[len - 1] + fib[len - 2]);
  }
}
vector<int> v;
bool used[MAXN];
vector<int> all;
long long memo[MAXN][MAXN];
void load(long long x) {
  v.clear();
  all.clear();
  memset(used, false, sizeof(used));
  for (int i = fib.size() - 1; i >= 0; i--) {
    if (x >= fib[i]) {
      x -= fib[i];
      all.push_back(i + 1);
    }
  }
}
bool split(int index) {
  if (index < 3) {
    used[index] = true;
    return false;
  }
  if (used[index - 1] == true || used[index - 2] == true) {
    used[index] = true;
    return false;
  }
  used[index - 1] = true;
  if (split(index - 2) == false) {
    used[index - 2] = true;
  }
  return true;
}
void prepareDP() {
  for (int i = all.size() - 1; i >= 0; i--) {
    if (split(all[i]) == false) {
      used[all[i]] = true;
    }
  }
  for (int i = 1; i < MAXN; i++) {
    if (used[i] == true) {
      v.push_back(i);
    }
  }
  memset(memo, -1, sizeof(memo));
}
long long calcState(int index, int last) {
  if (index == v.size()) return 1;
  if (last == v[index]) {
    if (index == v.size() - 1 || v[index] + 1 != v[index + 1]) return 0;
    return calcState(index + 2, v[index + 1] + 1);
  }
  if (memo[index][last] != -1) return memo[index][last];
  long long answer = 0;
  answer += calcState(index + 1, v[index]);
  if (last == v[index] - 1) answer += calcState(index + 1, v[index] + 1);
  memo[index][last] = answer;
  return answer;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q;
  precompute();
  cin >> Q;
  while (Q--) {
    long long x;
    cin >> x;
    load(x);
    prepareDP();
    cout << calcState(1, v[0]) << '\n';
  }
}
