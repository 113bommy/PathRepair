#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
bool desc(int i, int j) { return i > j; }
using namespace std;
int F[100 * 1000 + 100][3];
int A[3 * 100 * 1000 + 100];
int B[3 * 100 * 1000 + 100];
multiset<int>::iterator it;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> V;
  for (int(i) = (1); (i) < (10000); (i)++) {
    if (i % 2)
      V.push_back(i * (i - 1) / 2 + 1);
    else
      V.push_back(i * (i - 1) / 2 + (n - 2) / 2 + 1);
  }
  vector<int> Q;
  for (int(i) = 0; (i) < (m); (i)++) {
    int q, w;
    cin >> q >> w;
    Q.push_back(w);
  }
  sort(Q.begin(), Q.end(), desc);
  int k = 0;
  while (V[k] <= n) k++;
  long long ret = 0;
  for (int(i) = 0; (i) < (min(k, (int)Q.size())); (i)++) ret += Q[i];
  cout << ret << endl;
}
