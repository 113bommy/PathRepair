#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int out;
  string in;
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  int len = sizeof(primes) / sizeof(int);
  int count = 0;
  int num, i;
  for (i = 0; i < len; ++i) {
    cout << primes[i] << "\n";
    fflush(stdout);
    cin >> in;
    count += in[0] == 'y';
  }
  if (count == 0) {
    cout << "prime";
    fflush(stdout);
    return 0;
  }
  int squares[] = {4, 9, 16, 25};
  len = sizeof(squares) / sizeof(int);
  for (i = 0; i < len; ++i) {
    cout << squares[i] << "\n";
    fflush(stdout);
    cin >> in;
    count += in[0] == 'y';
  }
  cout << ((count == 1) ? "prime" : "composite");
  fflush(stdout);
  return 0;
}
