#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> memories;
  int n, temp;
  cin >> n;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    memories.push_back(temp);
  }
  if (n == 1) {
    if (memories.at(0) == 0) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (memories.at(i) == 0) {
        counter++;
      }
    }
    if (counter == 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
  return 0;
  system("pause");
}
