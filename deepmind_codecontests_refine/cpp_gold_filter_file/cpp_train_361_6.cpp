#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[27][3];
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  int n2 = n / 2;
  map<pair<int, int>, pair<int, int> > left;
  int pw = 1;
  for (int i = 0; i < n2; i++) pw *= 3;
  for (int i = 0; i < pw; i++) {
    int sm[3] = {0};
    int msk = i;
    for (int j = 0; j < n2; j++) {
      sm[(msk % 3 + 1) % 3] += a[j][(msk % 3 + 1) % 3];
      sm[(msk % 3 + 2) % 3] += a[j][(msk % 3 + 2) % 3];
      msk /= 3;
    }
    pair<int, int> in = make_pair(sm[1] - sm[0], sm[2] - sm[1]);
    if (!left.count(in))
      left[in] = make_pair(sm[0], i);
    else
      left[in] = max(left[in], make_pair(sm[0], i));
  }
  int n1 = n - n2;
  pw = 1;
  for (int i = 0; i < n1; i++) pw *= 3;
  int best = -1000000000;
  int msk1 = -1, msk2 = -1;
  for (int i = 0; i < pw; i++) {
    int sm[3] = {0};
    int msk = i;
    for (int j = n2; j < n; j++) {
      sm[(msk % 3 + 1) % 3] += a[j][(msk % 3 + 1) % 3];
      sm[(msk % 3 + 2) % 3] += a[j][(msk % 3 + 2) % 3];
      msk /= 3;
    }
    pair<int, int> in = make_pair(-(sm[1] - sm[0]), -(sm[2] - sm[1]));
    if (left.count(in)) {
      pair<int, int> r = left[in];
      if (sm[0] + r.first > best) {
        best = sm[0] + r.first;
        msk1 = i;
        msk2 = r.second;
      }
    }
  }
  string S = "LMW";
  if (msk1 == -1) {
    cout << "Impossible" << endl;
  } else {
    for (int i = 0; i < n2; i++) {
      cout << S[(msk2 % 3 + 1) % 3] << S[(msk2 % 3 + 2) % 3] << endl;
      msk2 /= 3;
    }
    for (int i = 0; i < n1; i++) {
      cout << S[(msk1 % 3 + 1) % 3] << S[(msk1 % 3 + 2) % 3] << endl;
      msk1 /= 3;
    }
  }
}
