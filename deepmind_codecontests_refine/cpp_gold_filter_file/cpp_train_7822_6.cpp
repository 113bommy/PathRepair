#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n, i, j = 0, x;
    cin >> n;
    string s = "";
    stack<long long> q;
    deque<long long> d;
    for (i = 0; i < (n); i++) {
      cin >> x;
      d.push_back(x);
    }
    q.push(0);
    while (!d.empty()) {
      if (d.front() > q.top() && (d.front() < d.back() || d.back() < q.top())) {
        q.push(d.front());
        s += 'L';
        d.pop_front();
      } else if (d.back() > q.top() &&
                 (d.front() >= d.back() || d.front() < q.top())) {
        q.push(d.back());
        s += 'R';
        d.pop_back();
      } else
        break;
    }
    cout << q.size() - 1 << "\n";
    cout << s;
  }
}
