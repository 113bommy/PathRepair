#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int numAdvancing = 0, p;
  int minScore = 0;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    if (p < minScore) break;
    if (i == k) minScore = p;
    numAdvancing++;
  }
  cout << numAdvancing;
}
