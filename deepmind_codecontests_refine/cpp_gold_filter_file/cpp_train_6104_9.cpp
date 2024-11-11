#include <bits/stdc++.h>
using namespace std;
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string d = "\"?";
unsigned long long lenght[100001];
char find(long long k, int n) {
  if (k >= lenght[n]) {
    return '.';
  }
  if (n == 0) return f0[k];
  if (k < a.size()) {
    return a[k];
  }
  if (k >= a.size() + lenght[n - 1] &&
      k < lenght[n] - lenght[n - 1] - d.size()) {
    return b[k - a.size() - lenght[n - 1]];
  }
  if (k == lenght[n] - 1) return '?';
  if (k == lenght[n] - 2) return '"';
  if (k >= a.size() && k < a.size() + lenght[n - 1]) {
    return find(k - a.size(), n - 1);
  }
  return find(k - a.size() - lenght[n - 1] - b.size(), n - 1);
}
int main() {
  lenght[0] = f0.size();
  for (int i = 1; i < 100001; i++) {
    lenght[i] = 2 * lenght[i - 1] + a.size() + b.size() + d.size();
  }
  int q;
  cin >> q;
  while (q--) {
    int n;
    long long k;
    cin >> n >> k;
    cout << find(k - 1, n);
  }
  return 0;
}
