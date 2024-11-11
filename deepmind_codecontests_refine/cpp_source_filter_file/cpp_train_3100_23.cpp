#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  cout << (10000 - N % 10000) % 10000 << endl;
}
