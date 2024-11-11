#include <bits/stdc++.h>
using namespace std;
void Process() {
  long long a;
  cin >> a;
  long long x = a / 4 + 1;
  if (a % 4 == 0) x--;
  for (long long i = 0; i <= a - x - 1; i++) cout << '9';
  for (long long i = 0; i <= x - 1; i++) cout << '8';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int N;
  cin >> N;
  cin.ignore();
  while (N--) {
    Process();
  }
}
