#include <bits/stdc++.h>
using namespace std;
long long D[1 << 18];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, R;
  cin >> N >> R;
  long long Q = (1 << N);
  double sum = 0;
  for (int i = 0; i < Q; i++) {
    long long q;
    cin >> q;
    D[i] = q;
    sum += q;
  }
  cout.precision(20);
  cout << sum / Q << "\n";
  for (int i = 0; i < R; i++) {
    long long a, b;
    cin >> a >> b;
    sum -= D[a];
    sum += b;
    D[a] = b;
    cout << sum / Q << "\n";
  }
  return 0;
}
