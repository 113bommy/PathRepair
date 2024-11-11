#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> o;
void print(vector<long long> v) {
  vector<long long>::iterator it = v.begin();
  while (it != v.end()) {
    cout << *it << " ";
    it++;
  }
  cout << endl;
}
void printp(vector<pair<int, int>> v) {
  vector<pair<int, int>>::iterator it = v.begin();
  while (it != v.end()) {
    cout << (*it).first << " " << (*it).second << endl;
    it++;
  }
}
long long gcd(long long x, long long y) {
  if (y == 0) {
    return x;
  }
  if (x != max(x, y)) swap(x, y);
  return gcd(y, x % y);
}
int main() {
  int n;
  cin >> n;
  long long a, b;
  a = b = 0;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(x - y);
    a += x;
    b += y;
  }
  sort(v.begin(), v.end(), greater<long long>());
  long long val = 0;
  for (int i = 0; i < n; i++) {
    val += (i + 1) * v[i];
  }
  long long ans = n * b - a + val;
  cout << ans << endl;
}
