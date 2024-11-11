#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int a=0;
  for(int i=0;i<4;i++){
    if(S[i]=="+"){a++;}
    else{a--;}
  }
  cout << a << endl;
}