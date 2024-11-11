#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<long long int> V;
long long int c(long long int x) {
  long long int k = 5, cnt = 0;
  while (k <= x) {
    cnt += x / k;
    k *= 5;
  }
  return cnt;
}
int main() {
  cin >> n;
  for (int i = 1; i <= 400005; i++) {
    if (c(i) == n) V.push_back(i);
  }
  cout << V.size() << endl;
  for (int i = 0; i < V.size(); i++) {
    cout << V[i] << " ";
  }
}
