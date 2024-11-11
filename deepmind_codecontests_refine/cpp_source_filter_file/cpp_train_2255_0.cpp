#include <bits/stdc++.h>
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
using namespace std;
const long long maxx = 2e5 + 10;
long long arr[maxx + 5], krr[maxx + 5], sum[maxx + 5];
vector<long long> v;
vector<long long>::iterator upper;
int main() {
  long long n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    arr[i] = x;
    sum[i] = x;
    if (i != 0) {
      sum[i] += sum[i - 1];
    }
    v.push_back(sum[i]);
  }
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    krr[i] = x;
  }
  long long arrow = 0;
  for (int i = 0; i < q; i++) {
    arrow += krr[i];
    upper = upper_bound(v.begin(), v.end(), arrow);
    int dead = (upper - v.begin());
    if (dead == n) {
      arrow = 0;
      dead = 0;
    }
    cout << n - dead << endl;
  }
  return 0;
}
