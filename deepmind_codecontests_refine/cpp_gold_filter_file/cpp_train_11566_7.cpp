#include <bits/stdc++.h>
using namespace std;
int main() {
  int size;
  int A[1000];
  for (int i = 0; i < 1000; i++) A[i] = 0;
  cin >> size;
  for (int i = 0; i < size; i++) cin >> A[i];
  int count = -1;
  int s[1000];
  int j = 0;
  for (int i = 0; i <= size; i++) {
    if (A[i + 1] == 1 || A[i + 1] == 0) {
      ++count;
      s[j] = A[i];
      j++;
    }
  }
  cout << count << endl;
  for (int i = 0; i < count; i++) {
    if (s[i] == 0) break;
    cout << s[i] << " ";
  }
  return 0;
}
