#include <bits/stdc++.h>
using namespace std;
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string fi0 = "What are you doing while sending \"";
string fi2 = "\"? Are you busy? Will you send \"";
string fi4 = "\"?";
const int N = 1e5 + 1;
const long long K = 1e18;
long long len[N];
char get(int n, long long k) {
  if (k >= len[n]) return '.';
  if (n == 0) return f0[k];
  if (k < fi0.size()) return fi0[k];
  k -= fi0.size();
  if (k < len[n - 1]) return get(n - 1, k);
  k -= len[n - 1];
  if (k < fi2.size()) return fi2[k];
  k -= fi2.size();
  if (k < len[n - 1]) return get(n - 1, k);
  k -= len[n - 1];
  return fi4[k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  len[0] = f0.size();
  for (int i = 1; i < N; i++) {
    if (len[i - 1] >= K) {
      len[i] = len[i - 1];
    } else {
      len[i] = fi0.size() + fi2.size() + fi4.size() + 2 * len[i - 1];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int n;
    long long k;
    cin >> n >> k;
    cout << get(n, k - 1);
  }
  cout << '\n';
  return 0;
}
