#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define rer(i,l,n) for(int i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){

	while(1){
		int data[7]={22,60,6,38,24,42,20},a=0,b=0,sum=0;
		char x;
		rer(i,1,8){
			rer(j,1,8){
				if(~(cin>>x)) return 0;
				//if(cin.eof()) return 0;//!!!!!!!
				if(x=='1'){
					if(a==0 && b==0){
						a=i; b=j;
					}else{
						sum+=10*(i-a)+j-b;
					}
				}
				//o(sum);
			}
		}
		rep(i,0,7){
			if(sum==data[i]){
				char c;
				c='A'+i;
				o(c); break;
			}
		}
	}
}