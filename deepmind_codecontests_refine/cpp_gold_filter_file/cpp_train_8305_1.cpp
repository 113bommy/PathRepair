#include<bits/stdc++.h>
using namespace std;

int S[100010],T[100010],n,P[100010];

long long int  ans;
int main(){
  
	cin >> n;
  
	int p[100010];
	for (int i=1;i<=n;i++)
		cin>> p[i];
  
  for(int i=1;i<=n;i++){
		P[p[i]]=i;
    
		S[i]=i-1;
    
		T[i]=i+1;
	}
	
	for (int i=1;i<=n;i++){
      
		int b=S[P[i]],a=S[b];
      
		int c=T[P[i]],d=T[c];
      
		if (b!=0) ans += 1ll*(b-a)*(c-P[i])*i;
		if (c!=n+1) ans += 1ll*(d-c)*(P[i]-b)*i;
		
		S[c]=b;
		T[b]=c;
	}
	
	cout<< ans << endl;
	
}
