#include <bits/stdc++.h>
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long find_gcd(long long a, long long b) {
  while (a != b) {
    if (a < b) {
      std::swap(a, b);
    }
    if (a - b > b)
      a -= ((a - b) / b) * b;
    else
      a -= b;
  }
  return a;
}
long long find_lowest_common_multiple(long long a, long long b) {
  long long gcd = find_gcd(a, b);
  long long answer = (a / gcd) * b;
  if (answer / b != a / gcd)
    return 0;
  else
    return answer;
}
int main(int argc, char **argv) {
  long long t, w, b;
  std::cin >> t >> w >> b;
  long long lcm = find_lowest_common_multiple(w, b);
  long long ties;
  if (lcm == 0)
    ties = min(t + 1, min(w, b)) - 1;
  else
    ties = (t / lcm) * min(w, b) + min(t % lcm + 1, min(w, b)) - 1;
  if (ties == 0) {
    std::cout << "0/1" << std::endl;
  } else {
    long long gcd = find_gcd(ties, t);
    std::cout << ties / gcd << "/" << t / gcd << std::endl;
  }
  return 0;
}
