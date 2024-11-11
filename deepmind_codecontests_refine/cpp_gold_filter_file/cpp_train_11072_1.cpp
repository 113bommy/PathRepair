#include <bits/stdc++.h>
using namespace std;
const int N = int(1e7) + 100;
int sp[N];
int main() {
  sp[1] = 1;
  for (int i = 2; i < N; i++) {
    if (sp[i]) continue;
    sp[i] = i;
    for (long long j = (long long)i * i; j < N; j += i) {
      sp[j] = i;
    }
  }
  int n, m;
  cin >> n >> m;
  vector<int> a(n), aa(n);
  vector<int> pa(N, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    aa[i] = a[i];
    while (sp[a[i]] != 1) {
      pa[sp[a[i]]]++;
      a[i] /= sp[a[i]];
    }
  }
  vector<int> b(m), bb(m);
  vector<int> pb(N, 0);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    bb[i] = b[i];
    while (sp[b[i]] != 1) {
      pb[sp[b[i]]]++;
      b[i] /= sp[b[i]];
    }
  }
  for (int i = 1; i < N; i++) {
    int p = min(pa[i], pb[i]);
    pa[i] = p;
    pb[i] = p;
  }
  for (int i = 0; i < n; i++) {
    int tmp = aa[i];
    long long correct = 1;
    while (sp[tmp] != 1) {
      int pr = sp[tmp];
      if (pa[pr]) {
        pa[pr]--;
      } else
        correct *= pr;
      tmp /= pr;
    }
    aa[i] = correct;
  }
  for (int i = 0; i < m; i++) {
    int tmp = bb[i];
    long long correct = 1;
    while (sp[tmp] != 1) {
      int pr = sp[tmp];
      if (pb[pr]) {
        pb[pr]--;
      } else
        correct *= pr;
      tmp /= pr;
    }
    bb[i] = correct;
  }
  cout << n << " " << m << endl;
  for (int i = 0; i < n; i++) {
    cout << aa[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < m; i++) {
    cout << bb[i] << " ";
  }
  return 0;
}
