#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  cout << min(min(A + B, B + C), C + A) << endl;
}
