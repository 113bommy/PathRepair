#include <bits/stdc++.h>
using namespace std;
void File() {
  freopen("output.txt", "w", stdout);
  freopen("input.txt", "r", stdin);
}
void fast() {
  ios::sync_with_stdio(NULL);
  cout.tie(NULL);
  cin.tie(NULL);
}
const double pi = 3.1415926;
const int nn = 1e5 + 10;
int arr1[nn];
int arr2[nn];
int main() {
  fast();
  int n, x;
  cin >> n;
  priority_queue<int> a, b;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push(x);
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    b.push(x);
  }
  int suma = 0, sumb = 0;
  for (int i = 0; ((int)((a).size())) || ((int)((b).size())); i++) {
    if ((i & 1) == 0) {
      if (((int)((b).size())) == 0) {
        suma += a.top();
        a.pop();
      } else if (((int)((a).size())) == 0)
        b.pop();
      else if (a.top() >= b.top()) {
        suma += a.top();
        a.pop();
      } else
        b.pop();
    } else {
      if (((int)((a).size())) == 0) {
        sumb += b.top();
        b.pop();
      } else if (((int)((b).size())) == 0)
        a.pop();
      else if (b.top() >= a.top()) {
        sumb += b.top();
        b.pop();
      } else
        a.pop();
    }
  }
  cout << suma - sumb << endl;
  return 0;
}
