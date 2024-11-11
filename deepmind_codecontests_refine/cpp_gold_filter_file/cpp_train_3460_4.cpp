#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9) + 99;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool sortbyfirstdec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first > b.first;
}
bool sortbyfirstinc(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b << " " << c << " " << c << endl;
  }
  return 0;
}
