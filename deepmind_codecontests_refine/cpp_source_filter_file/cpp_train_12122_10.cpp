#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2;
  cin >> n1 >> n2;
  vector<int> my1(n1, 1);
  vector<int> my2(n2);
  for (int i = 0; i < n2; i++) {
    cin >> my2[i];
    int k = my2[i] - 1;
    while (my1[k++] == 1) {
      my1[k - 1] = my2[i];
    }
  }
  copy(my1.begin(), my1.end(), ostream_iterator<int>(std::cout, " "));
}
