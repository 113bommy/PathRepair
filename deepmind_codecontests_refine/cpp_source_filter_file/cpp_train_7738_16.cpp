#include <bits/stdc++.h>
using namespace std;
bool check(int n, int k) {
  vector<bool> prime(n + 1, true);
  for (int i = 2 * 2; i <= n; i += 2) prime[i] = false;
  for (int i = 3; i <= n; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) prime[j] = false;
    }
  }
  vector<int> finalprime;
  unordered_set<int> st;
  for (int i = 2; i <= n; i++)
    if (prime[i]) {
      finalprime.push_back(i);
      st.insert(i);
    }
  int ans = 0;
  for (int i = 1; i < finalprime.size(); i++)
    if (st.count(finalprime[i - 1] + finalprime[i] + 1)) ans++;
  return ans == k;
}
int main() {
  int n, k;
  cin >> n >> k;
  if (check(n, k))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
