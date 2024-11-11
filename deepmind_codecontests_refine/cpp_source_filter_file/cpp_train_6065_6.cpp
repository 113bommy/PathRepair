#include <bits/stdc++.h>
using namespace std;
void solve() {
  unordered_set<long long> set;
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
    if (set.find(x) != set.end())
      count++;
    else
      set.insert(x);
  }
  cout << count << endl;
}
int main() { solve(); }
