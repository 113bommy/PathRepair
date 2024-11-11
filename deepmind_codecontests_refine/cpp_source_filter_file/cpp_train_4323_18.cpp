#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    a.push_back(1);
    while (a.size() > 1 && a[a.size() - 1] == a[a.size() - 2]) {
      long long x = a[a.size()];
      a.pop_back();
      a[a.size() - 1]++;
    }
  }
  for (long long i = 0; i < a.size(); i++) cout << a[i];
  return 0;
}
