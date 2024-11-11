#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%lld", &n);
  long long a[n + 5];
  for (long long i = 0; i < n; i++) scanf("%lld", &a[i]);
  long long l = 0, r = n - 1, left = -1, right = -1;
  long long seq = 0;
  string ansL = "", ansR = "", temp;
  while (l <= r) {
    if (a[l] > seq && a[r] > seq) {
      if (a[l] < a[r]) {
        ansL += "L";
        ansR += "L";
        seq = a[l];
        l++;
      } else if (a[l] > a[r]) {
        ansL += "R";
        ansR += "R";
        seq = a[r];
        r--;
      } else {
        if (l == r) {
          ansL += "R";
          ansR += "R";
          seq = a[r];
          r--;
        } else {
          left = l, right = r;
          break;
        }
      }
    } else if (a[l] > seq) {
      ansL += "L";
      ansR += "L";
      seq = a[l];
      l++;
    } else if (a[r] > seq) {
      ansL += "R";
      ansR += "R";
      seq = a[r];
      r--;
    } else {
      cout << ansL.size() << endl;
      cout << ansL;
      return 0;
    }
  }
  long long seqL = seq, seqR = seq;
  long long lt = left, rt = right;
  if (left != -1) {
    while (left < right) {
      if (a[left] > seqL) {
        ansL += "L";
        seqL = a[left];
        left++;
      } else
        break;
    }
    while (lt < rt) {
      if (a[rt] > seqR) {
        ansR += "R";
        seqR = a[rt];
        rt--;
      } else
        break;
    }
    if (ansL.size() > ansR.size()) {
      cout << ansL.size() << endl;
      cout << ansL;
    } else {
      cout << ansR.size() << endl;
      cout << ansR;
    }
  } else {
    cout << ansL.size() << endl;
    cout << ansL;
  }
}
