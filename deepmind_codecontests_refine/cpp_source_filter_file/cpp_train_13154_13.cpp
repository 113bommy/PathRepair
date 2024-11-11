#include <bits/stdc++.h>
using namespace std;
int main() {
  int name[100], i, j = 0;
  string codename;
  cin >> codename;
  for (i = 0; i < codename.length(); i++) {
    name[j] = (int)codename[i];
    j++;
  }
  sort(name, name + j);
  int count = 0;
  for (int k = 1; k < j; k++) {
    if (name[k] != name[k - 1]) {
      count++;
    }
  }
  if (count % 2 == 0) {
    cout << "IGNORE HIM! \n";
  } else {
    cout << "CHAT WITH HER! \n";
  }
  return 0;
}
