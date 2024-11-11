#include <bits/stdc++.h>
using namespace std;
void hinataVSsakura(void);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) hinataVSsakura();
  return 0;
}
struct jutsu {
  long long a, b, c, d;
};
bool jutsu_compare(jutsu s1, jutsu s2) { return s1.a < s2.a; }
long long ncr(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a < b) ? a : b; }
void swap(long long &a, long long &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
long long index(vector<long long> arr, long long val) {
  auto it = find((arr).begin(), (arr).end(), val);
  if (it != arr.end()) {
    long long ind = it - arr.begin();
    return ind;
  } else
    return -1;
}
void hinataVSsakura(void) {
  long long n;
  cin >> n;
  long long a = n;
  n = (n * (n - 1) / 2);
  long long win[51] = {0}, player[51] = {0};
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y;
    cin >> x >> y;
    player[x]++;
    player[y]++;
    win[x]++;
  }
  long long u = -1, v = -1;
  for (long long i = 0; i < 50; ++i) {
    if (u != -1 && v != -1) break;
    if (player[i] == a - 2 && u == -1)
      u = i;
    else if (player[i] == a - 2 && u != -1)
      v = i;
  }
  if (win[u] > win[v])
    cout << u << " " << v << endl;
  else if (win[v] > win[u])
    cout << v << " " << u << endl;
  else
    cout << u << " " << v << endl;
}
