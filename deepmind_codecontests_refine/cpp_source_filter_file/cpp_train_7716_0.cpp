#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main() {
  int n, k;
  cin >> n >> k;
  for (long long int i = 0; i < 31; i++) {
    if (n & (1LL << i)) pq.push(i);
  }
  int j = k - pq.size();
  if (j < 0) {
    cout << "NO";
    return 0;
  }
  int h;
  int flag = 0;
  while (j--) {
    h = pq.top();
    if (h == 1) {
      flag = 1;
      break;
    }
    pq.pop();
    pq.push(h - 1);
    pq.push(h - 1);
  }
  if (flag) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  while (pq.size() >= 1) {
    int X = pq.top();
    pq.pop();
    cout << (1 << X) << " ";
  }
  return 0;
}
