#include <bits/stdc++.h>
using namespace std;
bool isSubSequence(string str1, string str2, int m, int n) {
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (str1[j] == str2[i]) j++;
  }
  return (j == m);
}
int isPrime(long long n) {
  int i;
  for (i = 2; i < sqrt(n) + 1; i++)
    if (n % i == 0) return 0;
  return 1;
}
int isSquare(long long n) { return (long long)sqrt(n) * (sqrt(n)) == n; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);
  long long i, j, n, k, cnt = 0, l = 1, m, ans = 0;
  map<string, string> mm;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    mm[b] = a;
  }
  for (i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    b.erase(b.length() - 1);
    if (mm.find(b) != mm.end()) {
      cout << a << " " << b << " #" << mm[b] << endl;
      ;
    }
  }
  return 0;
}
