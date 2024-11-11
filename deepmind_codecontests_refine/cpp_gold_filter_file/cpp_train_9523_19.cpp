#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  long long k;
  cin >> n >> m;
  k = (1LL << (n - 1)) - 1LL;
  m--;
  k -= m;
  vector<long long> s;
  for (int i = 0; i < n - 1; i++) {
    s.push_back(k & 1LL);
    k >>= 1;
  }
  deque<int> p;
  p.push_back(n);
  for (int i = 0; i < n - 1; i++)
    if (s[i])
      p.push_front(n - i - 1);
    else
      p.push_back(n - i - 1);
  while (!p.empty()) {
    cout << p.front() << " ";
    p.pop_front();
  }
  return 0;
}
