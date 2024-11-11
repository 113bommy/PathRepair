#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> PQ;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  int sol = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    PQ.push(p);
    PQ.push(p);
    sol += p - PQ.top();
    PQ.pop();
  }
  cout << sol << endl;
  return 0;
}
