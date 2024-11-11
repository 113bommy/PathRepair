#include <bits/stdc++.h>
using namespace std;
int lemak1(int p[], int t[], int n, int c);
int red1(int p[], int t[], int n, int c);
int main() {
  int n, c;
  cin >> n >> c;
  int p[n], t[n], i;
  for (i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (i = 0; i < n; i++) {
    cin >> t[i];
  }
  int lemak = lemak1(p, t, n, c);
  int redwoosh = red1(p, t, n, c);
  if (lemak > redwoosh) {
    cout << "Limak";
  } else if (lemak == redwoosh) {
    cout << "Tie";
  } else {
    cout << "Radewoosh";
  }
  return 0;
}
int lemak1(int p[], int t[], int n, int c) {
  int s, d = 0, e, i;
  for (i = 0; i < n; i++) {
    s = 0;
    for (int j = 0; j <= i; j++) {
      s = s + t[j];
    }
    int b = p[i] - (c * s);
    e = (b > 0) ? b : 0;
    d = d + e;
  }
  return d;
}
int red1(int p[], int t[], int n, int c) {
  int s, d = 0, e, i;
  for (i = n - 1; i >= 0; i--) {
    s = 0;
    for (int j = n - 1; j >= i; j--) {
      s = s + t[j];
    }
    int b = p[i] - c * s;
    e = (b > 0) ? b : 0;
    d = d + e;
  }
  return d;
}
