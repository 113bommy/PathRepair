#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
int primes[100000];
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first > b.first;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long max = 0;
  vector<int> vec, vec1;
  long long h = 0, m = 0;
  for (int i = 0; i < n; i++) {
    h = h | a[i];
    m = m | b[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int s = a[i] | a[j];
      int p = b[i] | b[j];
      vec.push_back(s);
      vec1.push_back(p);
      a[i] = s;
      b[i] = p;
    }
  }
  vec.push_back(h);
  vec1.push_back(m);
  for (int i = 0; i < vec.size(); i++) {
    int ss = vec[i] + vec1[i];
    if (max < ss) {
      max = ss;
    }
  }
  cout << max;
  return 0;
}
