#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  priority_queue<int, std::vector<int>, std::greater<int> > both;
  priority_queue<int, std::vector<int>, std::greater<int> > alice;
  priority_queue<int, std::vector<int>, std::greater<int> > bob;
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (a && b) {
      both.push(t);
    }
    if (a && !b) {
      alice.push(t);
    }
    if (!a && b) {
      bob.push(t);
    }
  }
  int res = 0;
  while (k > 0 && (!alice.empty() && !bob.empty()) || !both.empty()) {
    k--;
    if (both.empty()) {
      res += bob.top() + alice.top();
      bob.pop();
      alice.pop();
    } else if (alice.empty() || bob.empty()) {
      res += both.top();
      both.pop();
    } else if ((alice.top() + bob.top() < both.top())) {
      res += bob.top() + alice.top();
      bob.pop();
      alice.pop();
    } else {
      res += both.top();
      both.pop();
    }
  }
  if (k > 0) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}
