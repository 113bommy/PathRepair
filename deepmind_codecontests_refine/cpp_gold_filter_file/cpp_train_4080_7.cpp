#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return ans;
}
int inp[200010];
int sm[200010];
int chk[200010];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> inp[i];
    chk[inp[i]]++;
  }
  for (int i = 1; i < 200010; i++) {
    sm[i] = chk[i] + sm[i - 1];
  }
  int fl = 0;
  int mncst = 1000000000;
  for (int i = 1; i < 200010; i++) {
    int pw = 2;
    int ind = 1;
    int cst = 0;
    int cnt = chk[i];
    while (i * pw < 200010) {
      if (cnt >= k) {
        fl = 1;
        mncst = min(mncst, cst - (ind - 1) * (cnt - k));
        break;
      }
      cnt += (sm[min(200009, i * pw + pw - 1)] - sm[i * pw - 1]);
      cst += (sm[min(200009, i * pw + pw - 1)] - sm[i * pw - 1]) * ind;
      pw = pw * 2;
      ind++;
    }
    if (cnt >= k) {
      fl = 1;
      mncst = min(mncst, cst - (ind - 1) * (cnt - k));
    }
  }
  if (fl) {
    cout << mncst << endl;
  } else {
    sort(inp, inp + n);
    int cnt = 0;
    for (int i = 0; i < k; i++) {
      int x = inp[i];
      while (x) {
        x = x / 2;
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
