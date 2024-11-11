#include <bits/stdc++.h>
using namespace std;
int main() {
  int S, A, B, TA, TB;
  cin >> S >> A >> B >> TA >> TB;
  int ta = 2 * TA + S * A, tb = 2 * TB + S * B;
  if (ta > tb) {
    cout << "First" << endl;
  } else if (ta < tb)
    cout << "Second" << endl;
  else
    cout << "Friendship" << endl;
}
