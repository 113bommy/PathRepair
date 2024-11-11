#include <iostream>
#include <vector>
using namespace std;
int main() {
  string S;
  cin >> S;
  for(int i=0; i<S.size(); i+=2) {
    if(S[i]=='L'||S[i+1]=='R') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;     