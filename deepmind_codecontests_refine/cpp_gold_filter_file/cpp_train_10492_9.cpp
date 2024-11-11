#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S == "hi" || S == "hihi" || S == "hihihi" || S == "hihihihi" || S == "hihihihihi")
    cout << "Yes" << endl;
  else cout << "No" << endl;
}