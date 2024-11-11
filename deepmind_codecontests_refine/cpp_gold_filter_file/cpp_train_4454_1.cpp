#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int sum = 0;
  for (auto x : s)
    sum = sum + (int)x - 48;
  if (sum % 9 == 0) cout << "Yes"; else cout << "No";
  return 0;
}