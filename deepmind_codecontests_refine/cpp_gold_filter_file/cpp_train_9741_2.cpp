#include <bits/stdc++.h>
using namespace ::std;
vector<int> crushes(101);
int n;
int recurs(int current, int parent, int depth) {
  if (current == parent) {
    return depth;
  } else if (depth == 105)
    return 0;
  depth = recurs(crushes[current], parent, depth + 1);
  return depth;
}
long long gcd(long long a, long long b) {
  if (a * b == 0) return max(a, b);
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  ifstream fin("input.txt");
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> crushes[i];
  }
  int status = 1;
  vector<int> lencyc(n + 1);
  for (int i = 1; i <= n; i++) {
    lencyc[i] = recurs(crushes[i], i, 1);
  }
  long long answ = 1;
  for (int i = 1; i <= n; i++) {
    if (lencyc[i] == 0) {
      answ = -1;
      break;
    }
    if (lencyc[i] % 2 == 0) lencyc[i] /= 2;
    answ = lcm(answ, lencyc[i]);
  }
  cout << answ << "\n";
  return 0;
}
