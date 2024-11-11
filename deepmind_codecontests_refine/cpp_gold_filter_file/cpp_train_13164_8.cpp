#include <bits/stdc++.h>
using namespace std;
struct pt {
  long double x, y, z;
  pt() {}
  pt(long double _x, long double _y, long double _z) : x(_x), y(_y), z(_z) {}
  pt(const pt &P) : x(P.x), y(P.y), z(P.z) {}
  long double length() { return sqrtl(x * x + y * y + z * z); }
};
pt operator+(const pt &A, const pt &B) {
  return pt(A.x + B.x, A.y + B.y, A.z + B.z);
}
pt operator-(const pt &A, const pt &B) {
  return pt(A.x - B.x, A.y - B.y, A.z - B.z);
}
pt P[6000];
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> P[i].x;
    cin >> P[i].y;
    cin >> P[i].z;
  }
  long double Min = 1e+100;
  for (int i = 1; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      long double T1, T2;
      T1 = (P[i] - P[0]).length();
      T2 = (P[j] - P[0]).length();
      long double minT = min(T1, T2);
      long double maxT = max(T1, T2);
      long double dT = maxT - minT;
      long double PiPjDist = (P[i] - P[j]).length();
      PiPjDist -= dT;
      PiPjDist /= 2;
      long double Tn = maxT + PiPjDist;
      Min = min(Min, Tn);
    }
  }
  cout.precision(50);
  cout << Min << endl;
  return 0;
}
