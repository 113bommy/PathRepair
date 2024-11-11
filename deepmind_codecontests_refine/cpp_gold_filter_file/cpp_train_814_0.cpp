#include <iostream>
using namespace std;
int main(){
  string a,b,c;
  cin>>a>>b>>c;
  cout<<(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0]?"YES":"NO")<<endl;
}
