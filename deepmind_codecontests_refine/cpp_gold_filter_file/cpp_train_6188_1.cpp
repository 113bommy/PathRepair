#include <bits/stdc++.h>
using namespace std;
long long N, A, B, V;
int main() {
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cin >> V;
    long long get = (V * A) / B;
    long long low = B * get;
    long long use = low / A;
    if (use * A < low) use++;
    cout << V - use;
  }
  cout << endl;
}
