#include <bits/stdc++.h>
using namespace std;
inline void readln(int &I) {
  I = 0;
  char C = getchar();
  while (!isdigit(C)) C = getchar();
  while (isdigit(C)) I = I * 10 + C - '0', C = getchar();
}
const int Size = 100005;
int n, c, a[Size], g[Size];
long long h[Size], f[Size];
vector<int> q;
void _out(vector<int> iq) {
  printf("[%d]::", iq.size());
  while (!iq.empty()) printf("%d ", iq.front()), iq.erase(iq.begin());
  putchar(10);
}
int main() {
  readln(n), readln(c);
  for (register int i = 1; i <= n; i++) {
    readln(a[i]);
    while (!q.empty() and q.front() + c <= i) q.erase(q.begin());
    while (!q.empty() and a[q.back()] >= a[i]) q.pop_back();
    q.push_back(i), g[i] = a[q.front()], h[i] = h[i - 1] + a[i];
  }
  for (register int i = 1; i <= n; i++)
    f[i] = min((i - c >= 0 ? f[i - c] : 0x7fffffff) + (h[i] - h[i - c]) - g[i],
               f[i - 1] + a[i]);
  printf("%I64d\n", f[n]);
}
