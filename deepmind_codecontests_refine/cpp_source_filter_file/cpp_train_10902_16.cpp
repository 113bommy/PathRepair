#include <bits/stdc++.h>
using namespace std;
char Nr[2000005];
int Nb[6000005];
int Pw[6000005];
int Power[10];
const double PI = acos(-1);
const double eps = 0.000001;
bool pp;
struct Complex {
  double a, b;
  Complex operator*(Complex who);
  Complex operator/(double x);
  Complex operator+(Complex who);
  Complex operator-(Complex who);
};
vector<Complex> A, B, aux;
Complex Complex ::operator*(Complex who) {
  return {a * who.a - b * who.b, a * who.b + b * who.a};
}
Complex Complex ::operator/(double x) { return {a / x, b / x}; }
Complex Complex ::operator+(Complex who) { return {a + who.a, b + who.b}; }
Complex Complex ::operator-(Complex who) { return {a - who.a, b - who.b}; }
void invSort(vector<Complex>& a, int left, int right) {
  if (left == right) return;
  for (int i = left; i <= right; i++) aux[i] = a[i];
  int pos = left;
  for (int i = left; i <= right; i += 2) a[pos++] = aux[i];
  for (int i = left + 1; i <= right; i += 2) a[pos++] = aux[i];
  invSort(a, left, (left + right) / 2);
  invSort(a, (left + right) / 2 + 1, right);
}
void FFT(vector<Complex>& a, int dim, double sign) {
  aux.resize(dim);
  invSort(a, 0, dim - 1);
  for (int len = 1; len * 2 <= dim; len *= 2) {
    Complex radix = {cos(sign * PI / len), sin(sign * PI / len)};
    for (int i = 0; i < dim; i += 2 * len) {
      Complex w = {1, 0};
      for (int j = 0; j < len; j++) {
        Complex v = a[i + j], u = a[i + j + len];
        a[i + j] = v + u * w;
        a[i + j + len] = v - u * w;
        w = w * radix;
      }
    }
  }
}
vector<Complex> multiply(vector<Complex> A) {
  int N = A.size();
  int dim = 1;
  while (dim < (N + N - 1) * 2) dim *= 2;
  while (A.size() < dim) A.push_back({0, 0});
  vector<Complex> C;
  C.resize(dim, {0, 0});
  FFT(A, dim, 1.00);
  for (int i = 0; i < dim; i++) {
    C[i] = A[i] * A[i];
  }
  FFT(C, dim, -1.00);
  for (int i = 0; i < C.size(); i++) {
    C[i] = C[i] / (double)dim;
  }
  return C;
}
void mul(int A[], int B) {
  int i, t = 0;
  for (i = 1; i <= A[0] || t; i++, t /= 1000) A[i] = (t += A[i] * B) % 1000;
  A[0] = i - 1;
}
void div(int A[], int B) {
  int i, t = 0;
  for (i = A[0]; i > 0; i--, t %= B) A[i] = (t = t * 1000 + A[i]) / B;
  for (; A[0] > 1 && !A[A[0]]; A[0]--)
    ;
}
void Read() {
  Power[0] = 1;
  for (int i = 1; i <= 5; i++) Power[i] = Power[i - 1] * 10;
  scanf("%s", Nr + 1);
  if (Nr[1] == '8') pp = 1;
  int len = strlen(Nr + 1);
  for (int i = 1; i <= len; i++) Nb[i] = Nr[i] - '0';
  reverse(Nb + 1, Nb + len + 1);
  int cnt = 0;
  for (int i = 1; i <= len; i += 3) {
    int val = 0;
    for (int j = 0; j < 3 && j + i <= len; j++) {
      val += Power[j] * Nb[i + j];
    }
    Nb[++cnt] = val;
  }
  Nb[0] = cnt;
}
vector<long long> sqr(vector<long long> A) {
  vector<Complex> X;
  for (int i = 0; i < A.size(); i++) {
    X.push_back({(double)A[i], 0.0});
  }
  X = multiply(X);
  long long t = 0;
  A.resize(X.size());
  for (int i = 0; i < X.size(); i++) {
    A[i] = (long long)(X[i].a + 0.5);
    long long x = A[i] + t;
    A[i] = x % 1000;
    t = x / 1000;
  }
  while (t != 0) {
    A.push_back(t % 1000);
    t /= 1000;
  }
  while (A.size() >= 1 && A[A.size() - 1] == 0) A.pop_back();
  return A;
}
vector<long long> mult(vector<long long> A, int B) {
  int i, t = 0;
  for (i = 0; i < A.size() || t; i++, t /= 1000) {
    if (i >= A.size()) A.push_back(0LL);
    A[i] = (t += A[i] * B) % 1000;
  }
  return A;
}
void fastPower(long long p) {
  vector<long long> A;
  Complex w = {1, 0};
  A.push_back(1);
  int pw = 1, cnt = 0;
  while (pw <= p) pw *= 2, cnt++;
  for (int k = cnt - 1; k >= 0; k--) {
    A = sqr(A);
    if ((p & (1 << k)) != 0) A = mult(A, 3);
  }
  while (A.size() >= 1 && A[A.size() - 1] == 0) A.pop_back();
  for (int i = 0; i < A.size(); i++) {
    Pw[i + 1] = A[i];
    ;
    Pw[0]++;
  }
}
bool compare(int A[], int B[]) {
  if (A[0] > B[0]) return 1;
  if (A[0] < B[0]) return 0;
  for (int i = B[0]; i >= 1; i--) {
    if (A[i] > B[i]) return 1;
    if (A[i] < B[i]) return 0;
  }
  return 0;
}
int nbDig() {
  int ans = Pw[0] * 3 - 3;
  int last = Pw[Pw[0]];
  while (last > 0) {
    ++ans;
    last /= 10;
  }
  return ans;
}
void Solve() {
  double x = log2(10.0) / log2(3.0);
  int len = strlen(Nr + 1);
  int p = (int)(x * (len - 1));
  p = max(1, p - 10);
  fastPower(p);
  while (compare(Nb, Pw) == 1) {
    mul(Pw, 3);
    ++p;
  }
  p *= 3;
  int ans = p;
  div(Pw, 3);
  mul(Pw, 2);
  p--;
  if (compare(Nb, Pw) == 0) {
    ans = min(ans, p);
  }
  div(Pw, 3);
  p -= 3;
  if (compare(Nb, Pw) == 0) {
    ans = min(ans, p);
  }
  mul(Pw, 2);
  p += 2;
  if (compare(Nb, Pw) == 0) {
    ans = min(ans, p);
  }
  cout << ans << "\n";
}
int main() {
  Read();
  if (Nb[0] == 1 && Nb[1] == 1) {
    cout << "1\n";
    return 0;
  }
  if (Nb[0] == 1 && Nb[1] == 3) {
    cout << "3\n";
    return 0;
  }
  Solve();
  return 0;
}
