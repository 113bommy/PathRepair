#include <bits/stdc++.h>
using namespace std;
struct exam {
  int a, b;
};
bool sort0(exam a, exam b) {
  if (a.a < b.a)
    return true;
  else if (a.a == b.a && a.b < b.b)
    return true;
  else
    return false;
}
int main() {
  int n;
  cin >> n;
  vector<exam> v(n);
  for (int i = 0; i < n; i++) cin >> v.at(i).a >> v.at(i).b;
  sort(v.begin(), v.end(), sort0);
  int k = 0;
  for (int i = 0; i < n; i++)
    if (v.at(i).b >= k) {
      k = v.at(i).b;
    } else {
      k = v.at(i).a;
    }
  cout << k;
  return 0;
}
