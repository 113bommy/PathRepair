#include <bits/stdc++.h>
using namespace std;
const int MAXN = 550;
map<int, int> qtd;
int total, primo[100100];
bool mrk[100100];
void achaprimos() {
  total = 0;
  bool flag = false;
  for (int i = 3; i * i <= (int)1E9; i += 2) {
    if (!mrk[i]) {
      primo[++total] = i;
      if (flag) continue;
      if (i * i * i * i > (int)1E9) {
        flag = true;
        continue;
      }
      for (int k = i * i; k * k <= (int)1E9; k += 2 * i) mrk[k] = true;
    }
  }
}
bool ehprimo(int N) {
  if (N == 1) return false;
  if (N == 2) return true;
  if (N % 2 == 0) return false;
  for (int i = 1; (i <= total && primo[i] * primo[i] <= N); i++)
    if (N % primo[i] == 0) return false;
  return true;
}
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0LL) return a;
  return gcd(b, a % b);
}
int antes(int N) {
  int resp = N;
  while (!ehprimo(resp)) resp--;
  return resp;
}
int depois(int N) {
  int resp = N + 1;
  while (!ehprimo(resp)) resp++;
  return resp;
}
void f(int N) {
  if (N == 2)
    printf("1/6\n");
  else if (N == 3)
    printf("7/30\n");
  else if (N == 4)
    printf("9/30\n");
  else {
    long long int pa, pb, resp;
    pa = antes(N);
    pb = depois(N);
    resp = (pa * pb - 2 * pa);
    resp -= ((pb - N - 1) * 2);
    long long int denominador;
    denominador = (pa * pb * 2);
    long long int mdc = gcd(resp, denominador);
    resp /= mdc;
    denominador /= mdc;
    printf("%I64d/%I64d\n", resp, denominador);
  }
}
int main() {
  achaprimos();
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    f(N);
  }
  return 0;
}
