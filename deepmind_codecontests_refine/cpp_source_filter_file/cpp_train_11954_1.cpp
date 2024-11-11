#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  cout << (N % M == 0) ? 0 : 1 << endl;
}