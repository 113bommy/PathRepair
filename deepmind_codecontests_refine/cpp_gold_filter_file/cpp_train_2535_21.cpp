#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  unsigned n(0);
  cin >> n;
  vector<unsigned> array(n, 0);
  for (unsigned it(0); it != n; ++it) {
    array[it] = it + 1;
  }
  --n;
  for (unsigned it(n); it > 0; --it) {
    swap(array[it], array[it - 1]);
  }
  ++n;
  for (unsigned it(0); it != n; ++it) {
    cout << array[it] << " ";
  }
  return 0;
}
