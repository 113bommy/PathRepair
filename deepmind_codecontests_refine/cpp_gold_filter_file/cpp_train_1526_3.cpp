#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cout.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cout << setprecision(14);
  long long N, A, B;
  long long first = 0;
  while (cin >> N >> A >> B) {
    A--, B--;
    first = 0;
    while (N) {
      if (N == 1) {
        cout << "Final!" << endl;
        break;
      }
      if (A == B) {
        cout << first << endl;
        break;
      }
      N /= 2;
      A /= 2;
      B /= 2;
      first++;
    }
  }
}
