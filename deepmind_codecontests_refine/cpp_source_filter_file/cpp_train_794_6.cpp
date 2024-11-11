#include <bits/stdc++.h>
using namespace std;
complex<double> tmp[1 << 18];
complex<double> roots[1 << 18];
void fft_init() {
  complex<double> i = {0, 1};
  double pi = acos(-1.);
  for (int k = 0; k < (1 << 18); k++) {
    roots[k] = exp(2 * k * pi * i / (double)(1 << 18));
  }
}
void fft(complex<double> *a, int n, bool inv) {
  if (n == 1) return;
  int m = 1 << (18 - ((int)log2(n)));
  for (int i = 0; i < n / 2; i++) {
    complex<double> s = a[i];
    complex<double> t = a[n / 2 + i];
    complex<double> w = inv ? 1. / roots[m * i] : roots[m * i];
    a[i] = s + t;
    a[n / 2 + i] = w * (s - t);
  }
  fft(a, n / 2, inv);
  fft(a + n / 2, n / 2, inv);
  for (int i = 0; i < n / 2; i++) tmp[i] = a[i];
  for (int i = 0; i < n / 2; i++) a[2 * i + 1] = a[n / 2 + i];
  for (int i = 0; i < n / 2; i++) a[2 * i] = tmp[i];
}
vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
  int n = (1 << (int)ceil(log2(a.size() + b.size() - 1)));
  vector<complex<double>> x(n, 0);
  vector<complex<double>> y(n, 0);
  vector<long long> res(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); i++) x[i] = a[i];
  for (int i = 0; i < b.size(); i++) y[i] = b[i];
  fft(&x[0], n, false);
  fft(&y[0], n, false);
  for (int i = 0; i < n; i++) x[i] *= y[i];
  fft(&x[0], n, true);
  for (int i = 0; i < res.size(); i++) {
    res[i] = round(x[i].real()) / n;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  fft_init();
  int n, m, k;
  map<int, int> colors;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int color;
    cin >> color;
    colors[color]++;
  }
  auto comp = [](const vector<long long> &a, const vector<long long> &b) {
    return a.size() > b.size();
  };
  priority_queue<vector<long long>, vector<vector<long long>>, decltype(comp)>
      pq(comp);
  for (auto color : colors) {
    vector<long long> poly(color.second + 1, 1);
    pq.push(poly);
  }
  while (pq.size() > 1) {
    vector<long long> a = pq.top();
    pq.pop();
    vector<long long> b = pq.top();
    pq.pop();
    vector<long long> c = multiply(a, b);
    for (int i = 0; i < c.size(); i++) c[i] %= 1009;
    pq.push(c);
  }
  auto result = pq.top();
  cout << result[k] << "\n";
  return 0;
}
