#include <bits/stdc++.h>
using namespace std;
const int N = 103;
bool mycomp(int x, int y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long k;
  cin >> k;
  long long n = s.length();
  pair<long long, long long> A[26];
  bool B[26];
  memset(B, 0, sizeof(B));
  memset(A, 0, sizeof(A));
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (A[s[i] - 'a'].first == 0) cnt++;
    A[s[i] - 'a'].first++;
    A[s[i] - 'a'].second = s[i] - 'a';
  }
  if (n <= k)
    cout << 0 << endl;
  else {
    sort(A, A + 26);
    for (long long i = 0; i < 26; i++) {
      if (A[i].first == 0) continue;
      if (k > A[i].first)
        k -= A[i].first, A[i].first = 0;
      else
        k = 0;
    }
    cnt = 0;
    string str = "";
    for (long long i = 0; i < 26; i++) {
      if (A[i].first == 0) continue;
      B[A[i].second] = true;
      cnt++;
    }
    for (long long i = 0; i < n; i++) {
      if (B[s[i] - 'a'] == false) continue;
      str += s[i];
    }
    cout << cnt << '\n' << str;
  }
}
