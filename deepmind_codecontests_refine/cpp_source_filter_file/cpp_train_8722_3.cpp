#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<string> w={"a","SAT","FRI","THU","WED","TUE","MON","SUN"}
  string a;
  cin >> a;
  for(int i=1;; i++){
    if(a==w.at(i)){
      cout << i << endl;
      return 0;
    }
  }
}