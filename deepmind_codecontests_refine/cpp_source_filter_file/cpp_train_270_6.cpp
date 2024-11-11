#include <bits/stdc++.h>
using namespace std;
inline int rei() {
  int x;
  cin >> x;
  return x;
}
inline long long rel() {
  long long x;
  cin >> x;
  return x;
}
inline string res() {
  string x;
  cin >> x;
  return x;
}
void Calc() {
  int N = rei();
  int f = 1;
  int t = 2;
  bool OK = true;
  for (int i = 0; i < N; i++) {
    int s = rei();
    if (s == f) {
      t = 6 - f - t;
    } else if (s == t) {
      s = 6 - f - t;
    } else {
      OK = false;
    }
  }
  if (OK) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.tie(0);
  Calc();
  return 0;
}
