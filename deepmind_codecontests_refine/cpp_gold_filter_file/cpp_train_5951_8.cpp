#include <bits/stdc++.h>
using namespace std;
map<int, int> freq;
int main() {
  int n;
  cin >> n;
  int w, mn;
  cin >> w;
  freq[w]++;
  mn = w;
  for (int i = 1; i < n; i++) {
    cin >> w;
    freq[w]++;
    mn = min(mn, w);
  }
  if (freq[mn] <= n / 2)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}
