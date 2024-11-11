#include <bits/stdc++.h>
using namespace std;
struct print {
 public:
  static void lnrev(vector<int> x) {
    long long int n = x.size();
    for (int i = n - 1; i >= 0; i--) cout << x[i] << " ";
    cout << endl;
  }
  static void ln(vector<long long int> y) {
    long long int n = y.size();
    for (long long int i = 0; i < n; i++) cout << y[i] << " ";
    cout << endl;
  }
};
long long int SUM(vector<int> temp) {
  long long int ans = 0;
  for (long long int i = 0; i < temp.size(); i++) {
    ans += temp[i];
  }
  return ans;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (!a) return b;
  return gcd(b % a, a);
}
int findGCD(int a, int b, int c) {
  int arr[3];
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  int result = arr[0];
  for (int i = 1; i < 3; i++) result = gcd(arr[i], result);
  return result;
}
vector<int> computeLPSArray(string pat) {
  int M = pat.size();
  vector<int> lps(M);
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
  TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
long long int nCrModpDP(long long int n, long long int r, long long int p) {
  long long int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
long long int nCrModpLucas(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int ni = n % p, ri = r % p;
  return (nCrModpLucas(n / p, r / p, p) * nCrModpDP(ni, ri, p)) % p;
}
int binarySearch(vector<int> arr, int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  int i = 0;
  int B[] = {1, 0, 1, 0, 1};
  int count = 0;
  while (i < n) {
    if (A[i] == 1) {
      if ((n - 1 - i) >= 5) {
        if (A[i] == 1 and A[i + 1] == 0 and A[i + 2] == 1 and A[i + 3] == 0 and
            A[i + 4] == 1) {
          A[i + 2] = 0;
          count++;
          i = i + 4;
        } else {
          i++;
        }
      } else {
        i++;
      }
    } else {
      i++;
    }
  }
  for (int i = 0; i < n - 2; i++) {
    if (A[i] == 1 and A[i + 1] == 0 and A[i + 2] == 1) count++;
  }
  cout << count << endl;
  return 0;
}
