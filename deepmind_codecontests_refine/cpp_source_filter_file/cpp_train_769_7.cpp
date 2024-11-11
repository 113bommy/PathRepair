#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &out, const vector<int> A) {
  for (int i = 0; i < (A.size()); ++i) out << A[i] << " ";
  return out;
}
template <class T>
void mini(T &a, const T &b) {
  if (b < a) a = b;
}
template <class T>
void maxi(T &a, const T &b) {
  if (b > a) a = b;
}
bool solve();
int main() {
  solve();
  return 0;
}
bool solve() {
  int N, ans;
  cin >> N;
  ans = N;
  vector<int> A(N);
  for (int i = 0; i < (N); ++i) cin >> A[i];
  sort((A).begin(), (A).end());
  int i, j;
  j = N / 2;
  for (i = 0; i < N / 2; i++) {
    while (j < N and A[i] * 2 > A[j]) j++;
    if (j == N) break;
    ans--;
  }
  cout << ans << endl;
  return true;
}
