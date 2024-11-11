#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n,m,p,q,r,x,y;
	vector<int>::iterator itx,ity,it;
	for(;cin>>n>>m>>p>>q>>r;cout<<x<<endl){
		vector<int> v1,v2;
		v1.push_back(0);
		for(v1.push_back(r);m--;v2.clear()){
			cin>>x>>y;
			itx=upper_bound(v1.begin(),v1.end(),x);
			ity=upper_bound(v1.begin(),v1.end(),y);
			
//			if( ity-v1.begin()+1 & 1 )v2.push_back(0);
//			v2.push_back(0);
			v2.insert(v2.end(),ity-v1.begin()&1?1:2,0);
			for(it=ity;it!=v1.end();++it)
				v2.push_back(*it - y);
			
			if(v1.end()-itx & 1)v2.push_back(n-y);
			for(it=itx;it!=ity;++it)
				v2.push_back(*it-x+n-y);
			
			it = v1.begin();
			if(ity-v1.begin() & 1)++it;
			if(!it[1])it+=2;
			if(*it+n-x==v2.back()){++it;v2.pop_back();}
			for(;it!=itx;++it)
				v2.push_back(*it+n-x);
			
			v1.swap(v2);
		}
		v1.insert( upper_bound(v1.begin(),v1.end(),p-1), 2, p-1);
		v1.insert( lower_bound(v1.begin(),v1.end(),q), q );
		v1.push_back(n);
		it = upper_bound(v1.begin(),v1.end(),p-1);
		if(it-v1.begin() & 1) --it;
		for(x=0;*it<q;it+=2)
			x+=it[1]-*it
	}
}