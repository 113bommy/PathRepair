#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
vector<vector<long long> > ans;
vector<bool> visited(9, 0);
bool check(long long b) {
  while (b != 0) {
    if (visited[b % 10] == 1) return 1;
    b = b / 10;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n, b, count = 0;
  cin >> n;
  b = n;
  while (b != 0) {
    visited[b % 10] = 1;
    b = b / 10;
  }
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (check(i)) count++;
      if (n / i != i)
        if (check(n / i)) count++;
    }
  }
  cout << count;
  return 0;
}
