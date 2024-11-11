#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    x = max(a, x);
  }
  for(int i = 0; i < m; i++){
    int b;
    cin >> b;
    y = min(b, y);
  }
  if(y - x > 0)
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}
