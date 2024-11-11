#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char ch) {
  ch = tolower(ch);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
inline bool isprime(int n) {
  if (n < 2 || (n % 2 == 0 && n != 2)) return false;
  for (int i = 3; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
class Union {
 private:
  vector<int> saizu, link;

 public:
  Union(int n) {
    saizu.assign(n, 1);
    link.resize(n);
    iota(link.begin(), link.end(), 0);
  }
  int find(int n) {
    if (link[n] == n) return n;
    return link[n] = find(link[n]);
  }
  int same(int a, int b) { return find(a) == find(b); }
  void unite(int a, int b) {
    if (same(a, b)) return;
    a = find(a);
    b = find(b);
    if (saizu[a] < saizu[b]) swap(a, b);
    saizu[a] += saizu[b];
    link[b] = a;
  }
  int getsize(int a) { return saizu[find(a)]; }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      cout << -1 << "\n";
    } else {
      long long cast = a / b / d;
      cout << a * (cast + 1) - cast * (cast + 1) / 2 * b * d << "\n";
    }
  }
  return 0;
}
