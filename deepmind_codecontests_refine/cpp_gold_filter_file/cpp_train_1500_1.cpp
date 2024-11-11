#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
string multiply(string num1, string num2) {
  int len1 = num1.size();
  int len2 = num2.size();
  if (len1 == 0 || len2 == 0) return "0";
  vector<int> result(len1 + len2, 0);
  int i_n1 = 0;
  int i_n2 = 0;
  for (int i = len1 - 1; i >= 0; i--) {
    int carry = 0;
    int n1 = num1[i] - '0';
    i_n2 = 0;
    for (int j = len2 - 1; j >= 0; j--) {
      int n2 = num2[j] - '0';
      int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
      carry = sum / 10;
      result[i_n1 + i_n2] = sum % 10;
      i_n2++;
    }
    if (carry > 0) result[i_n1 + i_n2] += carry;
    i_n1++;
  }
  int i = result.size() - 1;
  while (i >= 0 && result[i] == 0) i--;
  if (i == -1) return "0";
  string s = "";
  while (i >= 0) s += std::to_string(result[i--]);
  return s;
}
int isPrime(long long int n) {
  if (n <= 1) return 0;
  for (long long int i = 2; i < n; i++)
    if (n % i == 0) return 0;
  return 1;
}
long long int modFact(long long int n, long long int p) {
  if (n >= p) return 0;
  long long int result = 1;
  for (long long int i = 1; i <= n; i++) result = (result * i) % p;
  return result;
}
bool isSubSequence(string str1, string str2, int m, int n) {
  if (m == 0) return true;
  if (n == 0) return false;
  if (str1[m - 1] == str2[n - 1])
    return isSubSequence(str1, str2, m - 1, n - 1);
  return isSubSequence(str1, str2, m, n - 1);
}
long long int isSubstring(string s1, string s2) {
  long long int M = s1.length();
  long long int N = s2.length();
  for (long long int i = 0; i <= N - M; i++) {
    long long int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return i;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int s = 0, x1, x2, Y1, y2, xm = 1e10, ym = 1e10, xM = 0, yM = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> x1 >> Y1 >> x2 >> y2;
    xm = min(xm, x1), xM = max(xM, x1);
    xm = min(xm, x2), xM = max(xM, x2);
    ym = min(ym, Y1), yM = max(yM, Y1);
    ym = min(ym, y2), yM = max(yM, y2);
    s += (x2 - x1) * (y2 - Y1);
  }
  if (s == (xM - xm) * (yM - ym) && (xM - xm) == (yM - ym))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
