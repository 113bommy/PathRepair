#include <bits/stdc++.h>
#define repeat(i,a,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  vector<string> S(3);
  repeat(i,0,3) cin >>S[i];
  
  int i = 0;
  char ans;
  while(true){
    if (s[i].size()==0){
      ans = 'A'+i;
      break;
    }
    char front = s[i][0];
    s[i].erase(0,1);
    i = front - 'a';
  }

  cout <<ans<< endl;
}