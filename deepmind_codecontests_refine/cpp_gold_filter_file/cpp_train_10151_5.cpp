#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull euclid(const ull a, const ull b) { return (a == 0) ? b : euclid(b % a, a); }
int main() {
  ull t, a, b;
  cin >> t >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  const ull cmmdc = euclid(a, b);
  const ull nr_steps_a = t / a;
  const ull nr_steps_comun = (nr_steps_a / (b / cmmdc));
  const ull first_few = nr_steps_comun * a - 1;
  ull last_few = 0;
  if (nr_steps_comun == 0) {
    last_few = min(a, t + 1);
  } else {
    const ull last = ((nr_steps_comun * a) / cmmdc) * b;
    last_few = min(a, t - last + 1);
  }
  const ull rez = first_few + last_few;
  const ull cmmdc2 = euclid(rez, t);
  cout << (rez / cmmdc2) << '/' << (t / cmmdc2);
  return 0;
}
