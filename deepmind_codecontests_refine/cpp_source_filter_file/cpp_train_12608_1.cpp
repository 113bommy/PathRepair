#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  long long n;
  cin >> n;
  memset(a, 0, sizeof a);
  for (long long i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    vector<long long> dai;
    stack<long long> ss;
    for (long long j = 1; j * j <= temp && j * j <= n; j++) {
      if (temp % j == 0) {
        ss.push(j);
        if (temp / j != j && temp / j <= n) {
          a[temp / j] = (a[temp / j] + a[temp / j - 1]) % 1000000007;
        }
      }
    }
    while (!ss.empty()) {
      long long now = ss.top();
      ss.pop();
      if (now == 1) {
        a[now]++;
      } else
        a[now] = (a[now] + a[now - 1]) % 1000000007;
    }
  }
  long long counter = 0;
  for (long long i = 1; i <= n; i++) {
    counter = (counter + a[i]) % 1000000007;
  }
  cout << counter << endl;
  return 0;
}
