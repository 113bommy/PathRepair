#include <bits/stdc++.h>
using namespace std;
long long BigMod(long long int a, long long int b, int M) {
  long long remainder, answer = 1;
  remainder = a % M;
  while (b != 0) {
    if (b % 2 == 1) answer = (answer * remainder) % M;
    remainder = (remainder * remainder) % M;
    b /= 2;
  }
  return answer;
}
bool cmp(int a, int b) { return a > b; }
int main() {
  int n;
  scanf("%d", &(n));
  if (n % 2 == 0)
    cout << 4 << " " << n - 4;
  else
    cout << 9 << " " << n - 9;
  return 0;
}
