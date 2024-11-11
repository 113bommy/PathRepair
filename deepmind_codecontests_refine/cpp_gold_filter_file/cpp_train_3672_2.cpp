#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> V(n), jumps(n, 1e9 + 5);
  stack<int> mini, maxi;
  for (int i = 0; i < n; i++) cin >> V[i];
  mini.push(n - 1);
  maxi.push(n - 1);
  jumps[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    jumps[i] = jumps[i + 1] + 1;
    if (V[i] > V[i + 1]) {
      while (!maxi.empty() && V[maxi.top()] <= V[i]) {
        jumps[i] = min(jumps[i], jumps[maxi.top()] + 1);
        maxi.pop();
      }
      if (!maxi.empty()) {
        jumps[i] = min(jumps[i], jumps[maxi.top()] + 1);
      }
    } else if (V[i] < V[i + 1]) {
      while (!mini.empty() && V[mini.top()] >= V[i]) {
        jumps[i] = min(jumps[i], jumps[mini.top()] + 1);
        mini.pop();
      }
      if (!mini.empty()) {
        jumps[i] = min(jumps[i], jumps[mini.top()] + 1);
      }
    }
    while (!maxi.empty() && V[maxi.top()] <= V[i]) {
      maxi.pop();
    }
    while (!mini.empty() && V[mini.top()] >= V[i]) {
      mini.pop();
    }
    maxi.push(i);
    mini.push(i);
  }
  cout << jumps[0] << endl;
}
