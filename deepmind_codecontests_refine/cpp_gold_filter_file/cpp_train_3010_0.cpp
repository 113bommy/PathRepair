#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int r,c,q;
int r1,c1,r2,c2;
int tmp;
vector<int> seg[1000];

void init(int num,int n_){
  seg[num].clear();
  for(int i=0;i<2*n_-1;i++)seg[num].push_back( (1<<31)-1 );
}

void update(int x,int k, int a){
  k += n-1;
  seg[x][k] = a;
  while(k>0){
    k = (k-1) / 2;
    seg[x][k] = min(seg[x][k*2+1], seg[x][k*2+2]);
  }
}

int query(int x, int a, int b, int k, int l, int r){
  if(r<=a || b<=l)return (1<<31) - 1;
  if(a<=l && r<=b)return seg[x][k];
  else{
    return min(query(x,a,b,2*k+1,l,(l+r)/2),query(x,a,b,2*k+2,(l+r)/2,r));
  }
}

int main(){
  while(1){
    cin >> r >> c >> q;
    if(!r && !c && !q)break;

    if(r>=c){
      n = 1;
      while(n<r)n *= 2;
      for(int i=0;i<c;i++)init(i,n);
      for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
	  cin >> tmp;
	  update(j,i,tmp);
	}
      }
      while(q--){
	cin >> r1 >> c1 >> r2 >> c2;
	int ans = (1<<31) - 1;
	for(int i=c1;i<=c2;i++)ans = min(ans,query(i,r1,r2+1,0,0,n));
	cout << ans << endl;
      }
    }else{
      n = 1;
      while(n<c)n *= 2;
      for(int i=0;i<r;i++)init(i,n);
      for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
	  cin >> tmp;
	  update(i,j,tmp);
	}
      }
      while(q--){
	cin >> r1 >> c1 >> r2 >> c2;
	int ans = (1<<31) - 1;
	for(int i=r1;i<=r2;i++)ans = min(ans,query(i,c1,c2+1,0,0,n));
	cout << ans << endl;
      }
    }
  }
}