#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > xy;
vector<pair<long long, long long> > ab;
vector<long long> x;
vector<long long> y;
string str, str1, str2, star[2000];
long long ara[200005], ara2[200005];
bool flagar[200005], flagar2[200005];
bool compare(pair<long long, long long> i, pair<long long, long long> j) {
  return (i.first < j.first);
}
bool compare2(pair<long long, long long> i, pair<long long, long long> j) {
  return (i.first > j.first);
}
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long month[8][6];
long long dat[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  long long int n, ans, temp, t, j, i, m, h, h2, m2, c, a, b, mx, d, k;
  cin >> n >> m;
  temp = m;
  a = 1;
  j = m;
  for (i = 1; i <= dat[m - 1]; i++) {
    if (j == 8) {
      j = 1;
      a++;
    }
    month[a][j] = i;
    j++;
  }
  cout << a;
  return 0;
}
