#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T x) {
  cout << x << "\n";
}
template <typename T1, typename T2>
void print2(T1 x, T2 y) {
  cout << x << " " << y << "\n";
}
template <typename T1, typename T2, typename T3>
void print3(T1 x, T2 y, T3 z) {
  cout << x << " " << y << " " << z << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test_case;
  test_case = 1;
  while (test_case--) {
    long long n;
    cin >> n;
    vector<long long> alice(4), bob(4);
    for (int i = 1; i <= 3; i++) cin >> alice[i];
    for (int i = 1; i <= 3; i++) cin >> bob[i];
    long long maxwin = 0, minwin = 0;
    maxwin +=
        min(alice[1], bob[2]) + min(alice[2], bob[3]) + min(alice[3], bob[1]);
    if (alice[1] <= bob[3] + bob[1])
      minwin += 0;
    else
      minwin += alice[1] - bob[3] - bob[1];
    if (alice[2] <= bob[1] + bob[2])
      minwin += 0;
    else
      minwin += alice[2] - bob[1] - bob[2];
    if (alice[3] <= bob[2] + bob[3])
      minwin += 0;
    else
      minwin += alice[3] - bob[2] - bob[3];
    print2(minwin, maxwin);
  }
}
