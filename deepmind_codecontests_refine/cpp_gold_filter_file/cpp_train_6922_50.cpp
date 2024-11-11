#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, nA, nB;
  cin >> A >> B >> nA >> nB;
  vector<int> m(A), k(B);
  for (int i = 0; i < A; i++) cin >> m[i];
  for (int i = 0; i < B; i++) cin >> k[i];
  sort(m.begin(), m.end());
  sort(k.begin(), k.end());
  vector<int> a(nA), b(nB);
  for (int i = 0; i < nA; i++) a[i] = m[i];
  int j = 0;
  for (int i = B - 1; i > B - nB - 1; i--) {
    b[j] = k[i];
    j++;
  }
  int S = nA - 1;
  if (a[S] >= b[nB - 1])
    cout << "NO";
  else
    cout << "YES";
}
