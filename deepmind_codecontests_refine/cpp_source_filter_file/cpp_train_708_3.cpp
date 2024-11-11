#include <bits/stdc++.h>
using namespace std;
int main(){
 
 int A,B;
 cin >> A >> B;

 string s;
 cin >> s;
  for(int i=0;i<s.size();i++){
    if(i==A && s.at(i)!='-' || i!=A && s.at(i)=='-'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes"
}
