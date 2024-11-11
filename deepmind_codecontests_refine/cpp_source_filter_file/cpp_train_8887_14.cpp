#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int> > nails;
vector<vector<int> > rods;
int ma(int a) { return max(a, -a); }
int dist(vector<int>& A, vector<int>& B) {
  return ma(A[0] - B[0]) + ma(A[1] - B[1]);
}
int main() {
  cin >> N >> M;
  nails.resize(N, vector<int>(2));
  rods.resize(M, vector<int>(3));
  for (int n = 0; n < N; n++) {
    cin >> nails[n][0] >> nails[n][1];
  }
  for (int m = 0; m < M; m++) {
    cin >> rods[m][0];
    rods[m][1] = m + 1;
    rods[m][2] = 0;
  }
  sort(rods.begin(), rods.end(), less<vector<int> >());
  bool good = true;
  vector<int> ansvec(N, -1);
  for (int i = 0; i < N; i += 2) {
    int len = dist(nails[(i + N - 1) % N], nails[i]) +
              dist(nails[i], nails[(i + 1) % N]);
    int idx = -1;
    for (int i = 0; i < rods.size(); i++) {
      if (!rods[i][2] && rods[i][0] >= len) {
        idx = rods[i][1];
        rods[i][2] = 1;
        break;
      }
    }
    if (idx == -1) {
      good = false;
      break;
    }
    ansvec[i] = idx;
  }
  if (!good) {
    good = true;
    fill(ansvec.begin(), ansvec.end(), -1);
    for (int i = 0; i < rods.size(); i++) {
      rods[i][2] = 0;
    }
    for (int i = 1; i < N; i += 2) {
      int len = dist(nails[(i + N - 1) % N], nails[i]) +
                dist(nails[i], nails[(i + 1) % N]);
      int idx = -1;
      for (int i = 0; i < rods.size(); i++) {
        if (!rods[i][2] && rods[i][0] >= len) {
          idx = rods[i][1];
          rods[i][2] = 1;
          break;
        }
      }
      if (idx == -1) {
        good = false;
        break;
      }
      ansvec[i] = idx;
    }
  }
  if (!good) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < ansvec.size(); i++) {
      if (i > 0) cout << " ";
      cout << ansvec[i];
    }
    cout << endl;
  }
}
