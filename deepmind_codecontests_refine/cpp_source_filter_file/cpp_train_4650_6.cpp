#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k1, k2;
  cin >> n >> k1 >> k2;
  vector<long long> A(n);
  vector<long long> B(n);
  for (auto& e : A) cin >> e;
  for (auto& e : B) cin >> e;
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  long long totalOp = k1 + k2;
  for (long long i = 0; i < n; i++) {
    pq.push(abs((A[i] - B[i])));
  }
  long long res = 0;
  while (pq.empty() == false and totalOp > 0) {
    auto front = pq.top();
    pq.pop();
    if (front == 0) continue;
    totalOp--;
    pq.push(front - 1);
  }
  while (pq.empty() == false) {
    auto front = pq.top();
    pq.pop();
    res += front * front;
  }
  if (totalOp != 0) {
    cout << totalOp % 2 << endl;
  } else {
    cout << res << endl;
  }
}
