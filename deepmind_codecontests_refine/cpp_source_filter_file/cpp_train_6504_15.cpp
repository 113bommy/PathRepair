#include <bits/stdc++.h>
using namespace std;
int n;
int l[1 << 12];
int in[1 << 12];
int sm[1 << 12];
void go(int now) {
  if (now * 2 > (1 << n - 1)) return;
  int a = now * 2;
  int b = now * 2 + 1;
  go(a);
  go(b);
  int al = l[a] + in[a];
  int bl = l[b] + in[b];
  l[now] = max(al, bl);
  sm[now] = sm[a] + sm[b] + abs(al - bl);
};
int main() {
  cin >> n;
  n++;
  for (int i = 2; i <= 1 << n - 1; i++) {
    cin >> in[i];
  }
  go(1);
  cout << sm[1] << endl;
}
