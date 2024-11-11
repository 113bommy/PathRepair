#include <bits/stdc++.h>
using namespace std;
double a, b, c;
double getx(double x) { return (-c - b * x) / a; }
double gety(double x) { return (-c - a * x) / b; }
pair<double, double> A, B;
vector<double> Ans;
double dist(pair<double, double> x, pair<double, double> y) {
  double dx = x.first - y.first;
  double dy = x.second - y.second;
  return sqrt(dx * dx + dy * dy);
}
void show(pair<double, double> x) {
  cout << "(" << x.first << "," << x.second << ")" << endl;
}
int main() {
  cin >> a >> b >> c;
  cin >> A.first >> A.second >> B.first >> B.second;
  if (a == 0 || b == 0) {
    printf("%.13f", abs(A.first - B.first) + abs(A.second - B.second));
  } else {
    Ans.push_back(abs(A.first - B.first) + abs(A.second - B.second));
    pair<double, double> pvA, pvB, phA, phB;
    pvA = make_pair(A.first, gety(A.first));
    pvB = make_pair(B.first, gety(B.first));
    phA = make_pair(getx(A.second), A.second);
    phB = make_pair(getx(B.second), B.second);
    Ans.push_back(dist(A, pvA) + dist(B, pvB) + dist(pvA, pvB));
    Ans.push_back(dist(A, pvA) + dist(B, phB) + dist(pvA, phB));
    Ans.push_back(dist(A, phA) + dist(B, phB) + dist(phA, phB));
    Ans.push_back(dist(A, phA) + dist(B, pvB) + dist(phA, pvB));
    sort(Ans.begin(), Ans.end());
    printf("%.13f", Ans[0]);
  }
  printf("\n");
  return 0;
}
