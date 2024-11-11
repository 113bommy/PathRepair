#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a;
  cin>>n;
  set<int> s;
  while(cin>>a) s.insert(a);
  puts(s.size()==n?"YES":"NO");
}
