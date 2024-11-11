#include <bits/stdc++.h>
using namespace std;
void rev(vector<long long> &v) {
  for (int i = 0; i < v.size() / 2; ++i) {
    swap(v[i], v[v.size() - i - 1]);
  }
}
void rollback(vector<long long> &v) {
  for (int i = v.size() - 1; i > 0; --i) {
    v[i] -= v[i - 1];
  }
}
bool strictInc(vector<long long> &v) {
  for (int i = 1; i < v.size(); ++i) {
    if (v[i - 1] >= v[i]) {
      return false;
    }
  }
  return true;
}
bool strictDec(vector<long long> &v) {
  for (int i = 1; i < v.size(); ++i) {
    if (v[i - 1] <= v[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> A, B;
  A.resize(n);
  B.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> B[i];
  }
  vector<long long> RA = A;
  rev(RA);
  long long cnt1 = 0;
  long long cnt2 = 0;
  vector<char> rec;
  if (n == 2) {
    while (true) {
      if (A == B || B[0] == 0 || B[1] == 0) {
        break;
      }
      vector<long long> tB = B;
      if (A[0] == B[0]) {
        if ((tB[1] - A[1]) % tB[0] == 0) {
          B[1] = A[0];
          cnt2 += (tB[1] - A[1]) / tB[0];
          if (cnt2 <= 200000) {
            for (int i = 0; i < (tB[1] - A[1]) / tB[0]; ++i) {
              rec.push_back('P');
            }
          }
        }
        break;
      } else if (RA[0] == B[0]) {
        if ((tB[1] - RA[1]) % tB[0] == 0) {
          B = A;
          cnt2 += (tB[1] - RA[1]) / tB[0];
          if (cnt2 <= 200000) {
            for (int i = 0; i < (tB[1] - RA[1]) / tB[0]; ++i) {
              rec.push_back('P');
            }
            rec.push_back('R');
          }
          cnt1++;
        }
        break;
      } else {
        B = {tB[1] % tB[0], tB[0]};
        cnt2 += tB[1] / tB[0];
        if (cnt2 <= 200000) {
          for (int i = 0; i < tB[1] / tB[0]; ++i) {
            rec.push_back('P');
          }
          rec.push_back('R');
        }
        cnt1++;
      }
    }
  } else if (n > 2) {
    bool inc = strictInc(B);
    bool dec = strictDec(B);
    while (inc || dec) {
      if (A == B) {
        break;
      }
      if (inc) {
        cnt2++;
        rollback(B);
        if (cnt2 <= 200000) {
          rec.push_back('P');
        }
      } else if (dec) {
        cnt1++;
        rev(B);
        if (cnt2 <= 200000) {
          rec.push_back('R');
        }
      } else {
        break;
      }
      inc = strictInc(B);
      dec = strictDec(B);
    }
    if (RA == B) {
      cnt1++;
      rev(B);
      rec.push_back('R');
    }
  }
  if (A == B) {
    if (cnt2 <= 200000) {
      cout << "SMALL" << endl;
      cout << cnt1 + cnt2 << endl;
      for (int i = rec.size() - 1; i >= 0; --i) {
        cout << rec[i];
      }
      cout << endl;
    } else {
      cout << "BIG" << endl;
      cout << cnt2 << endl;
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
