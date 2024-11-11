#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int s[12]={1,2,1,3,1,3,1,1,3,1,3,1};
  if(s[a-1]==s[b-1]){
    cout << "Yes";
  }else{
    cout << "No";
  }
}
