#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long a[100001];
  long long i;
  for (i = (0); i < (n); ++i) {
    cin >> a[i];
  }
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (i = (0); i < (n); ++i) {
    pq.push(a[i]);
  }
  for (i = (0); i < (k); ++i) {
    long long d = pq.top();
    pq.pop();
    d = -d;
    pq.push(d);
  }
  long long s = 0;
  while (!pq.empty()) {
    s = s = +pq.top();
    pq.pop();
  }
  cout << s << endl;
  return 0;
}
