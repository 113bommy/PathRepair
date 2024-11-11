#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int n;
long long int k;
long long int ar[100005];
priority_queue<long long int, vector<long long int>, greater<long long int> >
    pq;
int main() {
  cin >> n >> k;
  long long int b;
  cin >> b;
  for (int i = 0; i < n; ++i) cin >> ar[i];
  long long int sum = 0;
  int ans = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    if (sum + ar[i] > b) ans = min(ans, i);
    sum += ar[i];
    pq.push(ar[i]);
    while (pq.size() >= k) {
      sum -= pq.top();
      pq.pop();
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
