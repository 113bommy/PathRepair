#include <iostream>
#include <vector>
using namespace std;
struct SegTree{
	//
	int n;
	vector<long long> dat,laz;
	//
	SegTree(int n_){
		init(n_);
	}
	//
	void init(int n_){
		n=1;
		while(n<n_){
			n*=2;
		}
		dat.resize(2*n-1);
		laz.resize(2*n-1);
		fill(dat.begin(),dat.end(),0);
		fill(laz,begin(),laz.end(),0);
	}
	//
	void eval(int l,int k){
		if(k*2+1<n*2-1){
			laz[k*2+1]+=laz[k];
			laz[k*2+2]+=laz[k];
		}
		dat[k]+=laz[k]*l;
		laz[k]=0;
	}
	//
	long long update(int a,int b,int x,int k=0,int l=0,int r=-1){
		if(r==-1){
			r=n;
		}
		eval(r-l,k);
		if(r<=a||b<=l){
			return dat[k]+laz[k]*(r-l);
		}else if(a<=l&&r<=b){
			return dat[k]+(laz[k]+=x)*(r-l);
		}else{
			eval(r-l,k);
			long long va=update(a,b,x,k*2+1,l,(l+r)/2);
			long long vb=update(a,b,x,k*2+2,(l+r)/2,r);
			return dat[k]=va+vb;
		}
	}
	//
	long long query(int a,int b,int k=0,int l=0,int r=-1){
		if(r==-1){
			r=n;
		}
		eval(r-l,k);
		if(r<=a||b<=l){
			return 0;
		}else if(a<=l&&r<=b){
			return dat[k];
		}else{
			long long va=query(a,b,k*2+1,l,(l+r)/2);
			long long vb=query(a,b,k*2+2,(l+r)/2,r);
			return va+vb;
		}
	}
	//
};
int main(){
	int N,Q;
	cin>>N>>Q;
	SegTree Seg(N);
	while(Q--){
		int C;
		cin>>C;
		if(C==1){
			int S,T;
			cin>>S>>T;
			cout<<Seg.query(S-1,T)<<endl;
		}else{
			int S,T,X;
			cin>>S>>T>>X;
			Seg.update(S-1,T,X);
		}
	}
	return 0;
}
