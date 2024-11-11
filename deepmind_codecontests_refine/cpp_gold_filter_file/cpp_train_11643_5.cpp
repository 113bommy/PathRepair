#include <iostream>
using namespace std;
int main(){
  string S;
  cin >> S;
  if(S[0]!=S[1] && S[1]!=S[2] && S[2]!=S[0]){
  	cout << "Yes";
    return 0;
  }
  cout << "No";
  return 0;
}