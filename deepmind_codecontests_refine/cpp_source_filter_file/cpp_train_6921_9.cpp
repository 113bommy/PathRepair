#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n;
int v[N];
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v + n);
  int totalServedTime = 0;
  int sad = 0;
  for (int i = 0; i < n; i++) {
    if (totalServedTime < v[i]) {
      totalServedTime += v[i];
    } else {
      sad++;
    }
  }
  cout << n - sad << endl;
  return 0;
}
