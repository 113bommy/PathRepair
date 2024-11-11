#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int n;
  cin >> n;
  int count = 0;
  int middle = 0;
  if (n % 2 == 0) {
    middle = n / 2;
  } else {
    middle = (n - 1) / 2;
  }
  for (int i = 1; i <= middle; i++) {
    if ((n - i) % i == 0) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
