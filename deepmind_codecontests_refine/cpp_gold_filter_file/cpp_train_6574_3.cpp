#include <bits/stdc++.h>
using namespace std;
int N, pr, pc;
int posr[2];
int posc[2];
int query(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  cout.flush();
  int x;
  cin >> x;
  return x;
}
void answer(int x1, int y1, int x2, int y2) {
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  cout.flush();
  exit(0);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int ans = query(i, 1, i, N) % 2;
    if (ans) posr[pr++] = i;
  }
  for (int i = 1; i <= N; i++) {
    int ans = query(1, i, N, i) % 2;
    if (ans) posc[pc++] = i;
  }
  if (pr == 2 && !pc) {
    int ini = 1;
    int fin = N;
    while (ini < fin) {
      int mid = (ini + fin) / 2;
      int ans = query(posr[0], ini, posr[0], mid) % 2;
      if (ans)
        fin = mid;
      else
        ini = mid + 1;
    }
    answer(posr[0], ini, posr[1], ini);
  } else if (!pr && pc == 2) {
    int ini = 1;
    int fin = N;
    while (ini < fin) {
      int mid = (ini + fin) / 2;
      int ans = query(ini, posc[0], mid, posc[0]) % 2;
      if (ans)
        fin = mid;
      else
        ini = mid + 1;
    }
    answer(ini, posc[0], ini, posc[1]);
  } else {
    int ini = 1;
    int fin = N;
    while (ini < fin) {
      int mid = (ini + fin) / 2;
      int ans = query(posr[0], ini, posr[0], mid) % 2;
      if (ans)
        fin = mid;
      else
        ini = mid + 1;
    }
    if (ini == posc[0])
      answer(posr[0], posc[0], posr[1], posc[1]);
    else
      answer(posr[0], posc[1], posr[1], posc[0]);
  }
  return 0;
}
