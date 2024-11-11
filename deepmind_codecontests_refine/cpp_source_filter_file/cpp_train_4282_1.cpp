#include <bits/stdc++.h>
using namespace std;
map<pair<pair<long long int, long long int>,
         pair<long long int, long long int>>,
    long long int>
    pqr;
map<pair<long long int, long long int>, long long int> xyz;
map<long long int, long long int, greater<long long int>> yz;
vector<pair<long long int, string>> a1;
vector<pair<long long int, long long int>> a2;
vector<pair<long long int, pair<long long int, long long int>>> a3;
bool isSubSequence(string str1, string str2, long long int m, long long int n) {
  if (m == 0) return true;
  if (n == 0) return false;
  if (str1[m - 1] == str2[n - 1])
    return isSubSequence(str1, str2, m - 1, n - 1);
  return isSubSequence(str1, str2, m, n - 1);
}
long long int fac[5005];
void output2(long long int t) {
  if (t > 2) {
    cout << "3"
         << " "
         << "1"
         << "\n";
    cout << "3"
         << " "
         << "2"
         << "\n";
    for (long long int i = 2; i < t - 1; i++) {
      cout << "3"
           << " " << i + 2 << "\n";
    }
  } else {
    for (long long int i = 0; i < t - 1; i++) {
      cout << "1"
           << " " << i + 2 << "\n";
    }
  }
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p,
                            long long int fac[]) {
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, s;
  cin >> n >> s;
  long long int arr[n + 2];
  long long int sum = 0;
  map<long long int, long long int> freq;
  for (long long int i = 1; i <= n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
    sum = sum + arr[i];
  }
  if (sum < s) {
    cout << "-1\n";
    return 0;
  }
  sort(arr, arr + n);
  long long int r = arr[0];
  long long int d = n - freq[r];
  long long int h = sum - freq[r] * r;
  long long int g = h - d * r;
  if (g >= s) {
    cout << r << "\n";
    return 0;
  }
  long long int w = n * r;
  long long int q = sum - w;
  s = s - q;
  long long int ans = w - s;
  cout << ans / n;
  return 0;
}
