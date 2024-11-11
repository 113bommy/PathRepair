#include <bits/stdc++.h>
using namespace std;
int H[2];
int T[2];
int L[2];
int R[2];
double P[2];
double S[2];
double X[2][3000][210];
vector<int> C;
int K;
void compute(int i, int t) {
  for (int a = (1); a <= (H[i]); ++a) {
    if (a > 0) {
      if (!(C[t % K] == (1 - i) || C[t % K] == 2)) {
        X[i][t + 1][a] += X[i][t][a];
      } else {
        for (int x = (L[1 - i]); x <= (R[1 - i]); ++x)
          X[i][t + 1][max(a - x, 0)] += (1 - P[1 - i]) / S[1 - i] * X[i][t][a];
        X[i][t + 1][a] += P[1 - i] * X[i][t][a];
      }
    } else {
      X[i][t + 1][a] += X[i][t][a];
    }
  }
}
void compute() {
  for (int i = (0); i <= (((2) - 1)); ++i)
    for (int t = (0); t <= (((3000) - 1)); ++t)
      for (int j = (0); j <= (((210) - 1)); ++j) X[i][t][j] = 0.0;
  X[0][0][H[0]] = 1.0;
  X[1][0][H[1]] = 1.0;
  for (int t = (0); t <= (((3000 - 1) - 1)); ++t) {
    compute(0, t);
    compute(1, t);
  }
}
void check() {
  for (int t = (0); t <= (3000 - 1); ++t) {
    if (X[0][t][0] >= 1 - 1E-10 && X[1][t][0] >= 1 - 1E-10) break;
    cout << t << endl;
    cout << "Player 0: " << endl;
    bool found = false;
    for (int a = (0); a <= (200); ++a) {
      if (X[0][t][a] > 1E-10)
        cout << a << " " << X[0][t][a] << endl, found = true;
    }
    cout << "Player 1: " << endl;
    for (int a = (0); a <= (200); ++a) {
      if (X[1][t][a] > 1E-10)
        cout << a << " " << X[1][t][a] << endl, found = true;
    }
    cout << endl;
    if (!found) break;
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  for (int i = (0); i <= (((2) - 1)); ++i)
    cin >> H[i] >> T[i] >> L[i] >> R[i] >> P[i], P[i] /= 100.,
        S[i] = R[i] - L[i] + 1;
  bool oneA = (abs(P[0] - 1) <= 1E-10) ? true : false;
  bool oneB = (abs(P[1] - 1) <= 1E-10) ? true : false;
  if (oneA) {
    cout << "0.000000000" << endl;
    return 0;
  } else if (oneB) {
    cout << "1.00000000" << endl;
    return 0;
  }
  int lcm = T[0] * T[1] / gcd(T[0], T[1]);
  for (int t = (0); t <= (((lcm)-1)); ++t) {
    int m1 = t % T[0];
    int m2 = t % T[1];
    if ((!m1) && (!m2))
      C.push_back(2);
    else if (!m1)
      C.push_back(0);
    else if (!m2)
      C.push_back(1);
  }
  K = C.size();
  compute();
  double ans = 0.0;
  for (int b = (1); b <= (H[1]); ++b) {
    int numchoices = R[0] - b + 1;
    numchoices = min(numchoices, R[0] - L[0] + 1);
    if (numchoices <= 0) break;
    for (int t = (0); t <= (3000 - 1); ++t) {
      if (!(C[t % K] == 0 || C[t % K] == 2)) continue;
      double adder = 0.0;
      for (int a = (1); a <= (H[0]); ++a) {
        adder += X[0][t][a];
      }
      adder *= X[1][t][b] * numchoices * (1 - P[0]) / S[0];
      ans += adder;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}
