#include <bits/stdc++.h>
using namespace std;
int N, K;
string H;
int l;
vector<int> psum;
int ldist(int J, int cnt) {
  if (J - psum[J] < cnt) return 987654321;
  int s = 0, e = J;
  int idx;
  while (true) {
    if (s > e) break;
    int mid = (s + e) / 2;
    int cow = psum[J];
    cow -= psum[mid];
    cow += H[mid] - '0';
    cow = J - mid - cow;
    if (cow == cnt) {
      if (H[mid] == '0') {
        idx = mid;
        break;
      } else {
        s = mid + 1;
      }
    } else if (cow < cnt) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return J - idx;
}
int rdist(int J, int cnt) {
  if (l - 1 - J - (psum[l - 1] - psum[J]) < cnt) return 987654321;
  int s = J, e = l - 1;
  int idx;
  while (true) {
    if (s > e) break;
    int mid = (s + e) / 2;
    int cow = psum[mid];
    cow -= psum[J];
    cow = mid - J - cow;
    if (cow == cnt) {
      if (H[mid] == '0') {
        idx = mid;
        break;
      } else {
        s = mid + 1;
      }
    } else if (cow < cnt) {
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return idx - J;
}
int main() {
  cin >> N >> K;
  cin >> H;
  l = H.size();
  psum.resize(l);
  for (int i = 0; i < l; i++) {
    psum[i] = H[i] - '0';
    if (i != 0) psum[i] += psum[i - 1];
  }
  int mini = 987654321;
  for (int i = 0; i < N; i++) {
    if (H[i] == '1') continue;
    int left = 0;
    if (i != 0) left = i - psum[i - 1];
    int s = 0, e = left;
    int cnt = 0;
    while (true) {
      if (s > e) break;
      int mid = (s + e) / 2;
      int ld = ldist(i, mid);
      int rd = rdist(i, K - mid);
      if (ld <= rd) {
        cnt = mid;
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    int c1 = max(ldist(i, cnt), rdist(i, K - cnt));
    mini = min(mini, c1);
    if (left > cnt) {
      int c2 = max(ldist(i, cnt + 1), rdist(i, K - cnt - 1));
      mini = min(mini, c2);
    }
  }
  cout << mini;
}
