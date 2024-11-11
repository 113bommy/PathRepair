#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
vector<long long> v;
void make_number(long long four, long long seven, long long number) {
  if (number > 1e9) return;
  if (number) v.push_back(number);
  long long n = number * 10 + 4;
  make_number(four + 1, seven, n);
  n = number * 10 + 7;
  make_number(four, seven + 1, n);
}
long long getAnswer(long long n) {
  if (n == 0) return 0;
  if (n < 4) {
    return n * 4;
  }
  long long sum = 0;
  for (int i = 1; i < v.size(); i++) {
    long long start = v[i - 1];
    long long end = min(v[i], n);
    long long value = v[i];
    if (start > end) break;
    if (start == 1) {
      sum += (end)*value;
    } else
      sum = sum + (end - start) * value;
  }
  return sum;
}
void solve() {
  v.push_back(1);
  make_number(0, 0, 0);
  sort(v.begin(), v.end());
  long long l, r;
  cin >> l >> r;
  long long a = getAnswer(r), b = getAnswer(l - 1);
  cout << a - b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
