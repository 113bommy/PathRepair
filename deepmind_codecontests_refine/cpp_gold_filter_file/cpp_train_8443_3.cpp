#include <bits/stdc++.h>
using namespace std;
int strin(char x) {
  if (x >= 'A') return 1;
  return 0;
}
int strtonum(string x) {
  int ret = 0;
  for (unsigned int i = 0; i < x.size(); i++) ret = ret * 10 + x[i] - '0';
  return ret;
}
string numtostr(int x) {
  string ret;
  while (x) {
    char c = ('0' + (x % 10));
    ret = c + ret;
    x /= 10;
  }
  return ret;
}
vector<int> prime;
void gen() {
  for (int i = 2; i < 1000; i++) prime.push_back(i);
  for (int i = 0; i < prime.size(); i++)
    for (int ii = i + 1; ii < prime.size(); ii++)
      if (prime[ii] % prime[i] == 0) {
        prime.erase(prime.begin() + ii);
        ii--;
      }
}
int tprime(long long x) {
  if (x == 1) return 0;
  if (x == 4 || x == 9 || x == 25) return 1;
  if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return 0;
  float s = sqrt(x);
  if (s == (int)s && x % (int)s == 0) {
    for (int i = 0; prime[i] <= sqrt(s) && i < prime.size(); i++)
      if ((int)s % prime[i] == 0) return 0;
    return 1;
  } else
    return 0;
}
long long sum(long long x) {
  long long y, tot = 0;
  while (x != 0) {
    y = x % 10;
    x = x / 10;
    tot += y;
  }
  return tot;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > mat(n, vector<int>(4));
  vector<int> er(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> mat[i][0] >> mat[i][1] >> mat[i][2] >> mat[i][3];
    for (int ii = 0; ii < i; ii++) {
      if (mat[i][0] < mat[ii][0] && mat[i][1] < mat[ii][1] &&
          mat[i][2] < mat[ii][2]) {
        er[i] = 0;
        break;
      }
      if (mat[i][0] > mat[ii][0] && mat[i][1] > mat[ii][1] &&
          mat[i][2] > mat[ii][2])
        er[ii] = 0;
    }
  }
  int minC = 1000, ind;
  for (int i = 0; i < n; i++)
    if (mat[i][3] <= minC && er[i]) {
      minC = mat[i][3];
      ind = i;
    }
  cout << ind + 1;
  return 0;
}
