#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main(){
  string s;cin >> s;
  int k;cin >> k;
  set<string> x;
  int l=(int)s.size();
  for(int i=1;i<=min({l,k});i++){
    for(int j=0;j<l-i+1;j++){
      x.insert(s.substr(j,i));
    }
  }
  int a=0;
  for(auto itr=x.begin();itr!=x.end();itr++){
    a++;
    if(a==k){cout << *itr << endl;break;}
  }
}
