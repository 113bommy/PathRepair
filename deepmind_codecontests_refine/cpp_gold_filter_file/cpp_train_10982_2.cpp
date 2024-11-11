#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
vector<int> guess;
bool prime(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void sol() {
  for (int i = 2; i <= n; i++) {
    if (prime(i)) {
      int j = i;
      while (j <= n) {
        guess.push_back(j);
        ans++;
        j *= i;
      }
    }
  }
}
int main() {
  cin >> n;
  sol();
  cout << ans << endl;
  for (int j : guess) cout << j << " ";
  cout << endl;
}
