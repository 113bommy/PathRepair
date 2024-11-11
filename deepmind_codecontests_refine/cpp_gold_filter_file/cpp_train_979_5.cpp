#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return a > b; }
int main() {
  long long n, s, x;
  vector<long long> middle;
  long long uppe = 0;
  long long lowe = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    long long m = s / 2;
    for (long long j = 0; j < s; j++) {
      cin >> x;
      if (j < m) uppe += x;
      if (s % 2 && j == m) middle.push_back(x);
      if (!(s % 2) && j == m) lowe += x;
      if (j > m) lowe += x;
    }
  }
  sort(middle.begin(), middle.end(), comp);
  for (long long i = 0; i < middle.size(); i++) {
    if (!(i % 2)) {
      uppe += middle[i];
    } else {
      lowe += middle[i];
    }
  }
  cout << uppe << " " << lowe << "\n";
  return 0;
}
