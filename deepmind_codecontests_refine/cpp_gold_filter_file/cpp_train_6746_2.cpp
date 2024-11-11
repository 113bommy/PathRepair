#include<bits/stdc++.h> 

using namespace std;

 int n;

multiset<int>s;

 set<int>::iterator it;

  int main()

   { scanf("%d",&n); for(int i=1;i<=n;i++) { int x; scanf("%d",&x); if(s.empty()) s.insert(x); else { it=s.lower_bound(x); if(it==s.begin()) s.insert(x); else { it--; s.erase(it); s.insert(x); } } } printf("%d\n",s.size()); } 

