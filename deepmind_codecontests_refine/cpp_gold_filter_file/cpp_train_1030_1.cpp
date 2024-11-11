#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF (1<<29)

int _not[3]={2,1,0};
int _and[3][3]={{0,0,0},{0,1,1},{0,1,2}};
int _or[3][3]={{0,1,2},{1,1,2},{2,2,2}};
int p,q,r;
char s[128],*pos;
int formula(){
	char c=*pos++;
	switch(c){
	case '0':return 0;
	case '1':return 1;
	case '2':return 2;
	case 'P':return p;
	case 'Q':return q;
	case 'R':return r;
	case '-':return _not[formula()];
	case '(':
		int a,b;
		a=formula();
		c=*pos++;
		b=formula();
		pos++;
		if(c=='*')return _and[a][b];
		return _or[a][b];
	}
	return -1;
}
int main(){
	while(cin>>s,s[0]!='.'){
		int ans=0;
		for(p=0;p<=2;p++){
			for(q=0;q<=2;q++){
				for(r=0;r<=2;r++){
					pos=s;
					if(formula()==2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}