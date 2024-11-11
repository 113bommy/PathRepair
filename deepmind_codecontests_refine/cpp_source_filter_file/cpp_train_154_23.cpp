#include <bits/stdc++.h>
std::string ans[12] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                       "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                       "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
const double EPS = 1e-10;
long double best;
int id;
bool better(long double val) {
  if (fabs(val - best) < EPS)
    return false;
  else if (best < val) {
    best = val;
    return true;
  }
  return false;
}
void try2(long double x, long double y, long double z, int pos) {
  long double val = z * y * log(x);
  if (better(val)) id = pos;
}
void try1(long double x, long double y, long double z, int pos) {
  long double val = pow(y, z) * log(x);
  if (better(val)) id = pos;
}
int main(void) {
  long double x, y, z;
  std::cin >> x >> y >> z;
  best = -1e12;
  id = -1;
  try1(x, y, z, 0);
  try1(x, z, y, 1);
  try2(x, y, z, 2);
  try2(x, z, y, 3);
  try1(y, x, z, 4);
  try1(y, z, x, 5);
  try2(y, x, z, 6);
  try2(y, z, x, 7);
  try1(z, x, y, 8);
  try1(z, y, x, 9);
  try2(z, x, y, 10);
  try2(z, y, x, 11);
  std::cout << ans[id] << '\n';
  return 0;
}
