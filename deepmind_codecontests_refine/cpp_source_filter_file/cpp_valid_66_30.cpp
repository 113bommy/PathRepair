#include <bits/stdc++.h>
using namespace std;
vector<int> jok;
int main() {
  int t, most, a;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> a;
    if (a <= jok.size())
      cout << jok[a - 1] << endl;
    else {
      if (jok.size() == 0)
        most = 1;
      else
        most = jok[jok.size() - 1] + 1;
      while (jok.size() < a) {
        if (most % 3 != 0 && most % 10 != 0) jok.push_back(most);
        most++;
      }
      cout << jok[a - 1] << endl;
    }
  }
  return 0;
}
