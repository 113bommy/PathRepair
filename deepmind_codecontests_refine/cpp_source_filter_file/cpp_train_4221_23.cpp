#include <bits/stdc++.h>
using namespace std;
void PR(vector<int>& v) {
  for (auto& x : v) cout << x << ' ';
  cout << endl;
}
int main() {
  cin.sync_with_stdio(false);
  int N;
  cin >> N;
  int res = 0;
  while (N) {
    int a = N & 7;
    if (a == 0) res++;
    N /= 8;
  }
  cout << res << endl;
}
