#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, count = 0, sum = 0;
  cin >> n >> k;
  int seq[n];
  set<int> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> seq[i];
    s.insert(seq[i]);
  }
  int d = s.size();
  for (int i = 1;; i++) {
    s.insert(i);
    int dd = s.size();
    if (d == dd)
      continue;
    else {
      d = dd;
      count++;
      if (i + sum <= k) {
        sum += i;
        v.push_back(i);
      } else
        break;
    }
  }
  if (count > 0) count--;
  cout << count << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}
