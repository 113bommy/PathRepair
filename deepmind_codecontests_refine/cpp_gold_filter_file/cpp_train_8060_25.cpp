#include <bits/stdc++.h>
using namespace std;
vector<long long> vc;
long long n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tk;
  long long sum = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> tk, vc.push_back(tk);
  }
  sort(vc.rbegin(), vc.rend());
  cout << vc[m - 1];
}
