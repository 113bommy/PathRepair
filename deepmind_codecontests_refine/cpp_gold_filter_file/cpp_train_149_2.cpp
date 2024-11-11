#include <bits/stdc++.h>
long long MOD = 1000000007;
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long POW(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % MOD;
  long long temp = POW(a, b / 2);
  if (b % 2 == 0)
    return (temp * temp) % MOD;
  else
    return (((temp * temp) % MOD) * a) % MOD;
}
vector<char> capl = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> sml = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
  int n, m;
  cin >> n >> m;
  int w[n], a[m];
  deque<int> d1, d2;
  map<int, int> m1;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    if (m1[a[i]] == 0) {
      d1.push_back(a[i]);
    }
    m1[a[i]]++;
  }
  int c, sum = 0;
  for (int i = 0; i < m; i++) {
    while (!d1.empty()) {
      c = d1.front();
      if (d1.front() == a[i]) {
        d1.pop_front();
        break;
      } else {
        sum += w[c - 1];
        d2.push_back(c);
        d1.pop_front();
      }
    }
    while (!d2.empty()) {
      d1.push_front(d2.back());
      d2.pop_back();
    }
    d1.push_front(c);
  }
  cout << sum;
}
