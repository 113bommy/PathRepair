#include <bits/stdc++.h>
using namespace std;
class Problem {
 private:
  long long first;
  long long second;
  long long third;
  long long forth;

 public:
  void setFirst(long long);
  long long getFirst();
  void setSecond(long long);
  long long getSecond();
  void setThird(long long);
  long long getThird();
  void setForth(long long);
  long long getForth();
  long long arr[10000];
};
void Problem::setFirst(long long one) { first = one; }
long long Problem::getFirst() { return first; }
void Problem::setSecond(long long two) { second = two; }
long long Problem::getSecond() { return second; }
void Problem::setThird(long long three) { third = three; }
long long Problem::getThird() { return third; }
void Problem::setForth(long long four) { forth = four; }
long long Problem::getForth() { return forth; }
long long solve(long long x, long long y, long long n) {
  if (n % 6 == 1)
    return x;
  else if (n % 6 == 2)
    return y;
  else if (n % 6 == 3)
    return y - x;
  else if (n % 6 == 4)
    return -x;
  else if (n % 6 == 5)
    return -y;
  else if (n % 6 == 0)
    return x - y;
}
long long resolve(long long x) {
  while (x < 0) x + 1000000007;
}
int main(int argc, char* argv[]) {
  Problem task;
  long long n, x, y;
  cin >> x >> y >> n;
  task.setFirst(x);
  task.setSecond(y);
  task.setThird(n);
  cout << (1000000007 * 3 + solve(x, y, n)) % 1000000007;
}
