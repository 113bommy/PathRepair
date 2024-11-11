#include <bits/stdc++.h>
using namespace std;
void swap(string &v, int a, int b) {
  int temp = v[a];
  v[a] = v[b];
  v[b] = temp;
}
int main() {
  string v;
  cin >> v;
  int len = v.size();
  int one = 0;
  int three = len - 1;
  while (one < len && (v[one] == '1')) {
    one += 2;
  }
  while (three >= 0 && (v[three] == '3')) {
    three -= 2;
  }
  int index = one;
  while (index <= three) {
    if ((v[index] == '1') && (index != one)) {
      swap(v, index, one);
      one += 2;
      continue;
    }
    if ((v[index] == '3') && (index != three)) {
      swap(v, index, three);
      three -= 2;
      continue;
    }
    index += 2;
  }
  cout << v;
  return 0;
}
