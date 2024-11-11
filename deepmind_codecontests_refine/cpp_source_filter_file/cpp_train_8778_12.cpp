#include <bits/stdc++.h>
using namespace std;
int main() {
  priority_queue<pair<unsigned long long int, int> > matches;
  unsigned long long int n;
  int m;
  unsigned long long int a;
  int b;
  unsigned long long int max = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    pair<int, unsigned long long int> d;
    d.first = b;
    d.second = a;
    matches.push(d);
  }
  while (matches.size() != 0 && m != 0) {
    pair<int, unsigned long long int> d = matches.top();
    if (a > n) {
      max += n * d.first;
      n = 0;
    } else {
      max += d.second * d.first;
      n -= d.second;
    }
    matches.pop();
  }
  cout << max << endl;
  return 0;
}
