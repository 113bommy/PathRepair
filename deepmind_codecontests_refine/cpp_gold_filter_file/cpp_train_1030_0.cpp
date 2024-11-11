#include<iostream>
#include<string>
using namespace std;

string exp;
int now,ans,p,q,r;

int multi(int x,int y){
	return min(x,y);
}

int myplus(int x,int y){
	return max(x,y);
}

int myminus(int x){
	if(x==2)
		return 0;
	if(x==1)
		return 1;
	if(x==0)
		return 2;
	return false;
}
int calc(){
	if(exp[now]=='0' || exp[now]=='1' || exp[now]=='2'){
		char temp=exp[now];
		now++;
		return temp-'0';
	}
	if(exp[now]=='P'){
		now++;
		return p;
	}else if(exp[now]=='Q'){
		now++;
		return q;
	}else if(exp[now]=='R'){
		now++;
		return r;
	}else if(exp[now]=='-'){
		now++;
		return myminus(calc());
	}else if(exp[now]=='('){
		now++;
		int left=calc(),right;
		if(exp[now]=='*'){
			now++;
			right=calc();
			now++;
			return multi(left,right);
		}
		else if(exp[now]=='+'){
			now++;
			right=calc();
			now++;
			return myplus(left,right);
		}
	}
	return false;
}

void solve(){
	now=0;
	ans=0;
	int k;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int z=0;z<3;z++){
				p=i;
				q=j;
				r=z;	
				k=calc();
				if(k==2){
					ans++;
				}
				now=0;
			}
	cout<<ans<<"\n";
}


int main()
{
	cin>>exp;
	while(exp!="."){
		solve();
		cin>>exp;
	}
	return 0;
}