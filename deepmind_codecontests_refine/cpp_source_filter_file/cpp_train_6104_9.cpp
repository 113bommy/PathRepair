#include <bits/stdc++.h>
using namespace std;
string S =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string A = "What are you doing while sending \"";
string B = "\"? Are you busy? Will you send \"";
string C = "\"?";
string arr[10];
long long len[5000000];
char dfs(long long n, long long p) {
  if (n == 0 && p < S.length()) return S[p];
  if (n == 0 && p >= S.length()) return '.';
  if (p < A.length())
    return A[p];
  else if (p < len[n - 1] + A.length())
    return dfs(n - 1, p - A.length());
  else if (p < A.length() + len[n - 1] + B.length())
    return B[p - A.length() - len[n - 1]];
  else if (p < A.length() + 2 * len[n - 1] + B.length())
    return dfs(n - 1, p - A.length() - len[n - 1] - B.length());
  else if (p < len[n])
    return C[p - A.length() - B.length() - 2 * len[n - 1]];
  else
    return '.';
}
int main() {
  len[0] = S.length();
  long long tmp;
  for (int i = 1; i <= 100020; ++i) {
    tmp = 2 * len[i - 1] + A.length() + B.length() + C.length();
    if (tmp > 1e19) {
      tmp = 1e18 + 7;
    }
    len[i] = tmp;
  }
  int q;
  cin >> q;
  long long n, k;
  for (int i = 0; i != q; ++i) {
    cin >> n >> k;
    --k;
    cout << dfs(n, k);
  }
}
