#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, hight, temp, width;
  cin >> num >> hight;
  vector<int> v;
  for (int i = 0; i < num; i++) {
    cin >> temp;
    v.push_back(temp);
    if (v[i] > hight)
      width += 2;
    else
      width++;
  }
  cout << width;
  return 0;
}
