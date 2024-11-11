#include <iostream>
#include <vector>
using namespace std;

int main(){
  string S;
  cin >> S;
  int ans = 1;
  if(S=="RRR") ans = 3;
  if(S=="RRS"||S=="SRR") ans = 2;
  if(S=="SSS") ans = 0;
  cout << ans;
  return 0;
}