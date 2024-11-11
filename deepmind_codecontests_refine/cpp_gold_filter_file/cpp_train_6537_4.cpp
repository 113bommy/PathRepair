#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> B(N-1);
  for (auto &i : B) cin >> i;
  
  int ans = B.front() + B.back();
  for (int i = 0; i < N-2; ++i) ans += min(B[i], B[i+1]);
  cout << ans << endl;
}
