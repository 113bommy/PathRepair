#include<bits/stdc++.h>
using namespace std;
 
int main() {
  
  int n,k=0,i;
  string s,r="Three";
  
  cin >> n;
  
  for(i=0;i<n;i++){
    
    cin >> s;
    if(s=="Y")r="Four";
    
  }
  
  cout << r << endl;
      
}
