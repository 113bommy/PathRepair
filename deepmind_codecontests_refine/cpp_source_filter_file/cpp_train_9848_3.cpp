#include <bits/stdc++.h>
using namespace std;
void promirzoprojects() {
  int n, k, sum = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < a.size(); i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }
  cout << sum << endl;
}
int main() {
  long long tests = 1;
  while (tests--) promirzoprojects();
  return 0;
}
