#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES" << endl; }
void NO() { cout << "NO" << endl; }
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ACC = 0;
  for (int i = 0; i < a - b; i++) {
    int k;
    cin >> k;
    ACC += k;
  }
  ACC += c;
  cout << ACC;
}
