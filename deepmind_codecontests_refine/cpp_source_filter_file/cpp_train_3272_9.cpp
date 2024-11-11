#include <bits/stdc++.h>
using namespace std;
int l[100];
int b[100];
void pri(int s, int e) {
  for (int i = s; i < e; i++) {
    cout << l[i] << ' ';
  }
  cout << endl;
}
void merg(int s, int v, int e) {
  int p1 = s;
  int p2 = v;
  int i = 0;
  while (p1 < v && p2 < e) {
    if (l[p1] > l[p2]) {
      b[i] = l[p1];
      p1++;
      i++;
    } else {
      b[i] = l[p2];
      p2++;
      i++;
    }
  }
  while (p1 < v) {
    b[i] = l[p1];
    i++;
    p1++;
  }
  while (p2 < e) {
    b[i] = l[p2];
    i++;
    p2++;
  }
  for (i = 0; i < e - s; i++) {
    l[s + i] = b[i];
  }
}
void mergsort(int s, int e) {
  if (e - s > 1) {
    int vasat = (s + e) / 2;
    mergsort(s, vasat);
    mergsort(vasat, e);
    merg(s, vasat, e);
  }
}
int main() {
  int n, v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v;
    l[i] = v;
  }
  mergsort(0, n);
  for (int i = 0; i < n; i++) {
    cout << l[i] << ' ';
  }
}
