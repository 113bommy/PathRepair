#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long int> ar;
unsigned long long int M, N, type, a, value, pos, sum;
int main() {
  cin >> N >> M;
  while (N--) {
    cin >> a;
    ar.push_back(a);
  }
  while (M--) {
    cin >> type;
    switch (type) {
      case 1:
        cin >> pos >> value;
        ar[pos - 1] = value;
        break;
      case 2:
        cin >> value;
        sum += value;
        break;
      case 3:
        cin >> pos;
        cout << ar[pos - 1] + sum << endl;
        break;
    }
  }
  return 0;
}
