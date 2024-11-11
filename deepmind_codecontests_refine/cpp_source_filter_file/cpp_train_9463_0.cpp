#include<set>
#include<iostream>
int main(){int l,r;for(;;){std::cin>>l>>r;if(!(l+=r))break;std::set<int> p;int m;p.insert(0);for(r=0;r<l;r++)std::cin>>m,p.insert(m);std::set<int>::iteratorツ　a;for(a=p.begin(),m=0;a!=--p.end();++a)if(*(++a)-*(--a)>m)m=*(++a)-*(--a);std::cout<<m<<"\n";}}