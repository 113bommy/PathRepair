#include <iostream>
#include <string>
#include <sstream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
ll p[19];
ll non(ll x){
	return x-x/3-x/5+x/15;
}
ll len(ll x){
	ll ret=0,num=x-x/3-x/5+x/15;
	int i;
	for(i=1;p[i]<=x;i++){
		ret+=(non(p[i]-1)-non(p[i-1]-1))*i;
		num-=(non(p[i]-1)-non(p[i-1]-1));
	}
	ret+=x/3*4;
	ret+=x/5*4;
	ret+=num*i;
	return ret;
}
string to_string(ll a){
	ostringstream os;
	os << a;
	return os.str();
}
int main(){
	ll s;
	cin >> s;
	p[0]=1;
	rep(i,18) p[i+1]=p[i]*10;
	ll ub=p[17],lb=0;
	while(ub-lb>1){
		ll m=(ub+lb)/2;
		if(s<=len(m)) ub=m;
		else lb=m;
	}
	string st;
	for(ll i=ub;st.size()<=50;i++){
		if(i%3==0 && i%5==0) st+="FizzBuzz";
		if(i%3==0 && i%5!=0) st+="Fizz";
		if(i%3!=0 && i%5==0) st+="Buzz";
		if(i%3!=0 && i%5!=0) st+=to_string(i);
	}
	cout << st.substr(s-1-len(lb),20) << endl;
}