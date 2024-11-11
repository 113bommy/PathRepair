#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<tuple>
#include<utility>
#include<set>
#include<queue>
#include<iomanip>
#include<iterator>
//#include<chrono>
#include<random>
using namespace std;
typedef long long int llint;
const int big=1e9+100000;
const int mod=1e9+7;
const long double pai=3.141592653589793238462643;
#define mt make_tuple
#define mp make_pair
#define fir first
#define sec second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define res resize
#define ins insert
#define era erase
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
int main(void){
	int i,n,m;
	cin>>n>>m;
	vector<string>word(n);
	vector<string>drow(n);
	for(i=0;i<n;i++){cin>>word[i];drow[i]=word[i];reverse(drow[i].begin(),drow[i].end());}
	sort(word.begin(),word.end());
	sort(drow.begin(),drow.end());
	for(i=0;i<m;i++){
		string sla;cin>>sla;
		int ans=0,bas=-1,rec=0,kak=0;
		if(sla[0]=='*'){reverse(sla.begin(),sla.end());rec=1;}
		if(sla.back()=='*'){kak++;sla.pob();}
		for(int j=0;j<sla.size();j++){
			if(sla[j]=='?'){bas=j;break;}
		}
		string slap=sla;
		for(char c='a';c<='z';c++){
			if(bas!=-1){sla[bas]=c;slap[bas]=c;}
			slap.back()++;
			if(kak==1){
				if(rec==0){ans+=lower_bound(word.begin(),word.end(),slap)-lower_bound(word.begin(),word.end(),sla);}
				else{ans+=lower_bound(drow.begin(),drow.end(),slap)-lower_bound(drow.begin(),drow.end(),sla);}
			}else{
				auto it=lower_bound(word.begin(),word.end(),sla);
				if(it!=word.end()&&(*it)==sla){ans++;}
			}
			slap.back()--;
		}
		if(bas==-1){ans/=26;}
		cout<<ans<<endl;
	}
}