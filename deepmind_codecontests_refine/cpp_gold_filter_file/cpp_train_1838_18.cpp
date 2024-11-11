#include <bits/stdc++.h>
using namespace std;
long long f(long long pre, long long k) {
  if (pre < 0)
    return -pre / k + (pre % k != 0);
  else
    return -pre / k;
}
int main() {
  long long p, k;
  cin >> p >> k;
  vector<long long> q;
  q.push_back(f(p, k));
  while (q.back() != 0) {
    q.push_back(f(q.back(), k));
    if (q.size() > 1e7) {
      cout << -1 << endl;
      return 0;
    }
  }
  q.pop_back();
  if (q.size() == 0) {
    cout << 1 << endl;
    cout << p << endl;
    return 0;
  }
  cout << q.size() + 1 << endl;
  cout << p + q[0] * k << " ";
  for (int i = 0; i < q.size() - 1; i++) cout << q[i] + q[i + 1] * k << " ";
  cout << q.back() << endl;
}
