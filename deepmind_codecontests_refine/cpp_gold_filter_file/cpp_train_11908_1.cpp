#include <bits/stdc++.h>
using namespace std;
int main() {
  long long arr[100005], m = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  stack<long long> s;
  s.push(arr[0]);
  for (int i = 1; i < n; i++) {
    while (s.top() < arr[i] && s.size()) {
      m = max((s.top() ^ arr[i]), m);
      s.pop();
      if (s.empty()) break;
    }
    if (s.size()) {
      if (s.top() > arr[i]) m = max((s.top() ^ arr[i]), m);
    }
    s.push(arr[i]);
  }
  cout << m;
}
