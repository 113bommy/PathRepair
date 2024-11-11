#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  unsigned long long a;
  vector<long long> count;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    count.push_back(a);
  }
  sort(count.begin(), count.end());
  unsigned long long total = 0;
  unsigned long long previous = count[n - 1] + 1;
  for (int i = (n - 1); i >= 0; i--) {
    if (previous <= count[i])
      previous--;
    else
      previous = count[i];
    total += (previous > 0) * previous;
  }
  cout << total << endl;
}
