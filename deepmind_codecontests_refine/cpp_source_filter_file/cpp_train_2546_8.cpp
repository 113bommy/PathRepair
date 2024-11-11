#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double g = 9.8;
int N, M;
double V, H;
pair<double, double> A[100100];
pair<double, double> W[100100];
pair<double, double> sol[100100];
double xt(int i, double t) { return V * cos(A[i].first) * t; }
double yt(int i, double t) { return V * sin(A[i].first) * t - (g * t * t) / 2; }
double val(int i, double x) { return yt(i, x / (V * cos(A[i].first))); }
double zero(int i) {
  double a = -g / 2;
  double b = V * sin(A[i].first);
  double c = 0;
  double D = b * b - 4 * a * c;
  double x1 = (-b + sqrt(D)) / (2 * a);
  double x2 = (-b - sqrt(D)) / (2 * a);
  return xt(i, max(x1, x2));
}
bool ok(int i, int p) { return val(i, W[p].first) > W[p].second + EPS; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(10) << fixed;
  cin >> N >> V;
  for (int I = 1; I <= N; I++) {
    cin >> A[I].first;
    A[I].second = I;
  }
  cin >> M;
  for (int I = 1; I <= M; I++) {
    cin >> W[I].first >> W[I].second;
  }
  sort(A + 1, A + 1 + N);
  sort(W + 1, W + 1 + N);
  int p = 1;
  for (int I = 1; I <= N; I++) {
    if (p > M) {
      sol[int(A[I].second)] = pair<double, double>(zero(I), 0);
      continue;
    }
    while (p <= M && ok(I, p)) p++;
    if (p > M) {
      sol[int(A[I].second)] = pair<double, double>(zero(I), 0);
      continue;
    }
    H = val(I, W[p].first);
    if (H <= 0)
      sol[int(A[I].second)] = pair<double, double>(zero(I), 0);
    else
      sol[int(A[I].second)] = pair<double, double>(W[p].first, H);
  }
  for (int I = 1; I <= N; I++)
    cout << sol[I].first << " " << sol[I].second << "\n";
}
