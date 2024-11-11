#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  if (N == 5) {
    cout << "1 2 3" << endl;
    cout << "1 3 3" << endl;
    cout << "2 4 2" << endl;
    cout << "4 5 1" << endl;
    cout << "3 4" << endl;
    cout << "3 5" << endl;
  } else {
    for (int i = 1; i <= N / 2; i++)
      cout << i << " " << i + N / 2 << " " << 1 << endl;
    for (int i = N / 2 + 1; i < N; i++)
      cout << i << " " << i + 1 << " " << 2 * (i - N / 2) - 1 << endl;
    cout << 1 << " " << 2 << endl;
    cout << "1 3" << endl;
    for (int i = 2; i < N / 2; i++) cout << i << " " << i + 1 << endl;
  }
  return 0;
}
