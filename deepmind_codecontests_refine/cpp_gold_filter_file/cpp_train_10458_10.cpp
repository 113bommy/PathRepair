#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int nums[10] = {0};
  set<int> stick;
  int input;
  int leg;
  for (int i = 0; i < 6; ++i) {
    cin >> input;
    ++nums[input];
    stick.insert(input);
  }
  for (int i = 1; i < 10; ++i) {
    if (nums[i] == 4) {
      if (stick.size() == 2)
        cout << "Elephant" << endl;
      else if (stick.size() == 3)
        cout << "Bear" << endl;
      return 0;
    } else if (nums[i] == 5) {
      cout << "Bear" << endl;
      return 0;
    } else if (nums[i] == 6) {
      cout << "Elephant" << endl;
      return 0;
    }
  }
  cout << "Alien" << endl;
  return 0;
}
