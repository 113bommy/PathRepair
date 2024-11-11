#include <bits/stdc++.h>
using namespace std;
const int INF = 1001000000;
int main() {
  int n, k;
  cin >> n >> k;
  int* A = new int[n];
  bool* B = new bool[n];
  string s;
  int js, jf, vs, vf;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[0] == '?') {
      B[i] = 1;
    } else {
      B[i] = 0;
      A[i] = stoi(s);
    }
  }
  for (int i = 0; i < k; i++) {
    js = i - k;
    vs = -INF;
    int j;
    for (j = i; j < n; j += k)
      if (!B[j]) {
        vf = A[j];
        jf = j;
        int jn = ((jf - js) / k);
        if ((vf - vs) < jn) {
          cout << "Incorrect sequence";
          return 0;
        }
        if (jn > 1)
          if (-(jn - 1) / 2 < vs + 1)
            for (int t = js + k; t < jf; t += k) {
              A[t] = vs + (t - js) / k;
            }
          else if ((jn - 2) / 2 > vf - 1)
            for (int t = jf - k; t > js; t -= k) {
              A[t] = vf - (jf - t) / k;
            }
          else
            for (int t = js + k; t < jf; t += k) {
              A[t] = -(jn - 1) / 2 + (t - js) / k - 1;
            }
        vs = A[j];
        js = j;
      }
    jf = j;
    vf = INF;
    int jn = ((jf - js) / k);
    if ((vf - vs) < jn) {
      cout << "Incorrect sequence";
      return 0;
    }
    if (jn > 1)
      if (-(jn - 1) / 2 < vs + 1)
        for (int t = js + k; t < jf; t += k) {
          A[t] = vs + (t - js) / k;
        }
      else if ((jn - 2) / 2 > vf - 1)
        for (int t = jf - k; t > js; t -= k) {
          A[t] = vf - (jf - t) / k;
        }
      else
        for (int t = js + k; t < jf; t += k) {
          A[t] = -(jn - 1) / 2 + (t - js) / k - 1;
        }
  }
  for (int i = 0; i < n; i++) cout << A[i] << " ";
  return 0;
}
