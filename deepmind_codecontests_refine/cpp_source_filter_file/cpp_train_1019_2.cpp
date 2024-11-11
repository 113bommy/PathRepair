#include <iostream>
#include <stirng>

using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int wcnt=0;
  for(int i=0;i<n;++i){
    if(s[i]=='.') wcnt++;
  }
  int min=n,lb=0,rw=wcnt;
  for(int i=0;i<n;++i){
    if(min>lb+rw) min = lb+rw;
    if(s[i]=='#') lb++;
    else if(s[i]=='.') rw--;
  }
  if(min>lb+rw) min = lb+rw;
  cout << min << endl;
  
  return 0;
}
