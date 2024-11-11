#include<bits/sydc++.h>
using namespace std;
int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  for(int i=0;i<n;i++){
    if(s.at(i)!=s.at(k)){
      s.at(i)='*';
    }
  }
 cout << s << endl;
}