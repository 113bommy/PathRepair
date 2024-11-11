#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
const int bigN = 1e9 + 5;
int mod = 1e9 + 7;
int arr[N], temp[N];
;
int arr1[N];
int matrix[100][100], matrix2[100][100], matrix3[100][100];
bool boolArr[N];
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long n;
int main() {
  init();
  int c = 0;
  map<int, int> m;
  cin >> n;
  for (int i = (0); i < (int)(n); ++i) {
    int x;
    cin >> x;
    m[x]++;
    if (m[x] > n / 2 + 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
