#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long f[n], s[n];
  set<long long> fr, sr;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == (n - 1)) {
      fr.insert(f[i]);
      sr.insert(s[i]);
      continue;
    }
    auto it = sr.end();
    it--;
    int temp = (*it + f[i]);
    auto itt = fr.end();
    itt--;
    sr.insert(*itt + s[i]);
    fr.insert(temp);
  }
  auto it = sr.end();
  it--;
  auto itt = fr.end();
  itt--;
  cout << max(*it, *itt);
}
