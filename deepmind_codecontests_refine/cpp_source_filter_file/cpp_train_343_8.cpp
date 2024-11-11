#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000")
using namespace std;
int n, k;
vector<pair<int, int> > A;
vector<pair<int, int> > B;
int T[50001], D[50001];
vector<int> R[1024];
int main() {
  cin >> n >> k;
  for (int(i) = (0); (i) < (n); ++(i)) {
    int a, b;
    cin >> a >> b;
    if (b == 1)
      A.push_back(make_pair(a, i));
    else
      B.push_back(make_pair(a, i));
    T[i] = b;
    D[i] = a;
  }
  if (A.size() < k) {
    for (int(i) = (0); (i) < (A.size()); ++(i)) R[i].push_back(A[i].second);
    int t = k - A.size();
    for (int(i) = (0); (i) < (B.size()); ++(i))
      R[A.size() + (i % t)].push_back(B[i].second);
  } else {
    sort((A).begin(), (A).end());
    reverse((A).begin(), (A).end());
    for (int(i) = (0); (i) < (k - 1); ++(i)) R[i].push_back(A[i].second);
    for (int(i) = (k - 1); (i) < (A.size()); ++(i))
      R[k - 1].push_back(A[i].second);
    for (int(i) = (0); (i) < (B.size()); ++(i)) R[k - 1].push_back(B[i].second);
  }
  double sum = 0;
  for (int(i) = (0); (i) < (k); ++(i)) {
    int m = 1000000000 + 1;
    bool was = false;
    int s = 0;
    for (int(j) = (0); (j) < (R[i].size()); ++(j)) {
      if (T[R[i][j]] == 1) was = true;
      m = min(m, D[R[i][j]]);
      s += D[R[i][j]];
    }
    if (was)
      sum += (s - m) + (m / 2.0);
    else
      sum += s;
  }
  printf("%0.1f\n", sum);
  for (int(i) = (0); (i) < (k); ++(i)) {
    cout << R[i].size();
    for (int(j) = (0); (j) < (R[i].size()); ++(j)) cout << ' ' << R[i][j] + 1;
    cout << endl;
  }
  return 0;
}
