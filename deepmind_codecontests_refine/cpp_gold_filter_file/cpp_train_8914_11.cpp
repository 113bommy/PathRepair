#include <bits/stdc++.h>
using namespace std;
const int MAX_PEOPLE = 100 * 1000;
int la_queue[MAX_PEOPLE], lowest[MAX_PEOPLE];
int N;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> la_queue[i];
  lowest[N - 1] = la_queue[N - 1];
  for (int i = N - 2; 0 <= i; i--) lowest[i] = min(lowest[i + 1], la_queue[i]);
  for (int i = 0; i < N - 1; i++) {
    int deb = i + 1, fin = N - 1;
    if (la_queue[i] <= lowest[deb]) {
      cout << -1 << ' ';
      continue;
    }
    while (1 < fin - deb) {
      int milieu = (fin + deb) / 2;
      if (lowest[milieu] < la_queue[i])
        deb = milieu;
      else
        fin = milieu;
    }
    if (lowest[fin] < la_queue[i])
      cout << fin - i - 1 << ' ';
    else
      cout << deb - i - 1 << ' ';
  }
  cout << -1;
  return 0;
}
