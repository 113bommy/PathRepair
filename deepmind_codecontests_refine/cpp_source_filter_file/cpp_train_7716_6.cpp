#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, less<long long> > Q;
int main() {
  long long N, i, j, k, K;
  cin >> N >> K;
  vector<int> X;
  k = 0;
  for (i = 32; i >= 0; i--) {
    if ((1LL << i) & N) {
      Q.push(1LL << i);
      k++;
    }
  }
  int ptr = 0;
  while (k < K && ptr < 10) {
    int x = Q.top();
    Q.pop();
    if (x % 2 == 0) {
      Q.push(x / 2);
      Q.push(x / 2);
      k++;
    }
    ptr++;
  }
  if (k != K) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  while (!Q.empty()) {
    cout << Q.top() << " ";
    Q.pop();
  }
  return 0;
}
