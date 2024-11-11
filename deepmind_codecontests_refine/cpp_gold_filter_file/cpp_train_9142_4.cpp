#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> a;
  for (int i = 0;i<N;i++) {
    int b;
    cin >> b;
    a.insert(b);
  }
  cout << a.size() << endl;
}
