#include <bits/stdc++.h>
using namespace std;
stack<time_t> time_stack;
void startTimer() { time_stack.push(clock()); }
double stopTimer() {
  double time = clock() - time_stack.top();
  time_stack.pop();
  return time / double(CLOCKS_PER_SEC);
}
bool prime(int n) {
  bool res = true;
  for (int i = 2; i * i <= n && res; i++) res = n % i != 0;
  return res;
}
int main() {
  startTimer();
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 2; i < n; i++) {
    if (!prime(i)) continue;
    int p = i;
    while (p <= n) {
      ans.push_back(p);
      p *= i;
    }
  }
  cout << ans.size() << endl;
  for (auto &it : ans) cout << it << " ";
  cout << endl;
  return 0;
}
