#include <iostream>

using namespace std;

int main()  {
  string a,b;
  cin>>a>>b;
  b.pop_back();
  if(a==b) cout<<"Yes";
  else cout<<"No";
}