#include <bits/stdc++.h>
using namespace std;
void quickSort(int *arr, int front, int end);
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int requests;
  cin >> requests;
  for (int i = 0; i < requests; i++) {
    int checkout;
    cin >> checkout;
    if (checkout % 3 == 2)
      cout << checkout % 3 << " " << checkout % 3 + 1 << endl;
    else if (checkout % 3 == 1)
      cout << checkout % 3 + 1 << " " << checkout % 3 << endl;
    else
      cout << checkout % 3 << " " << checkout % 3 << endl;
  }
}
