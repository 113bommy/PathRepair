#include <bits/stdc++.h>
using namespace std;
void Fast_Read_Out() {
  ios_base::sync_with_stdio(0);
  cin.tie(), cout.tie();
}
void Random() {
  unsigned int seed;
  asm("rdtsc" : "=A"(seed));
  srand(seed);
}
unsigned int Time() {
  unsigned int time = clock() / 1000.00;
  return time;
}
const int N = int(1e5) + 123;
const int inf = int(1e9) + 123;
int a[N];
int main() {
  Random();
  Fast_Read_Out();
  int n, nechet = 0, chet = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1)
      nechet++;
    else
      chet++;
  }
  int cnt = 0;
  while (chet > 0 && nechet > 0) {
    chet--;
    nechet--;
    cnt++;
  }
  cout << cnt + nechet / 2;
}
