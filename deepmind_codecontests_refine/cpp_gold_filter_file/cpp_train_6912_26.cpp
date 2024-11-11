#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int N;
  cin >> N;
  string A;
  cin >> A;
  int count = 0;
  for (int i = 0; i < ((int)(A).size()); i += N) {
    if (i >= 3) {
      if (A[i - 1] == A[i - 2] && A[i - 2] == A[i - 3]) count++;
    }
  }
  cout << count << endl;
  return 0;
}
