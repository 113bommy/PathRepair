#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (p[i] == i + 1) {
      i++;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}