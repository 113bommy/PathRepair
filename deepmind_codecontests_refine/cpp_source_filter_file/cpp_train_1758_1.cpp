#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef __int64 ll;
//typedef long long ll;
ll n;

int main(){
	while(cin>>n){
		if(!n)return 0;
		ll m=n,d=1,p;
		while(m>7){m/=8;d++;}
		for(int i=d-1;i>=0;i--){
			p=(n/(int)(pow(8,i)+0.1))%8;
			if(p<4)cout<<p;
			else if(p<5)cout<<p+1;
			else cout<<p+2;
		}
		cout<<endl;
	}
}