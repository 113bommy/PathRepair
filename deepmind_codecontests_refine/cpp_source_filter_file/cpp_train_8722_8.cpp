#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> d={"SUN","MON","TUE","WED","THU","FRI","SAT"}
  string t;
  cin>>t;
  for(int i=0; i<7; i++){
    if(t == d[i]){
      cout << 7-i << endl;
      return 0;
    }
  }
}