#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cerr << "--> " << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cerr << "--> " << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5
       << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cerr << "--> " << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5
       << " " << e6 << endl;
}
long long ara[100005];
struct data {
  long long a, b, c;
} arr[100005];
long long ak[105];
int main() {
  long long n, m, k;
  scanf("%I64d %I64d %I64d", &n, &m, &k);
  memset(ara, 0, sizeof(ara));
  for (int i = 0; i < m; i++) {
    scanf("%I64d %I64d %I64d", &arr[i].a, &arr[i].b, &arr[i].c);
  }
  for (int i = 0; i < k; i++) scanf("%I64d", &ak[i]);
  sort(ak, ak + k);
  for (int i = 0; i < m; i++) {
    long long l = arr[i].a, h = arr[i].b, val = arr[i].c;
    for (int j = 0; j < k; j++) {
      if (ak[j] >= l and ak[j] <= h) {
        long long d = ak[j] - l;
        ara[ak[j]] += (d + val);
      }
    }
  }
  long long sum = 0;
  for (int j = 0; j < k; j++) {
    sum += ara[ak[j]];
  }
  printf("%d\n", sum);
  return 0;
}
