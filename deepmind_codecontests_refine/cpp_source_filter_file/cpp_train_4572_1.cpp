#include <iostream>
#include <complex>

using namespace std;

#define COMP complex<int>
int abs(int a) {return (a<0) ?-a:a}

char *p, buf[11000];

COMP expr();

COMP fact(){
	COMP ret;
	if(*p == '('){
		p++;
		ret=expr();
		p++;
	}else if(*p == 'i'){
		ret=COMP(0,1);
		p++;
	}else{
		while(isdigit(*p)){
			ret = ret * 10 + int(*p - '0');
			p ++;
			if(abs(ret.real()) > 10000 || abs(ret.imag()) > 10000) throw 0;
		}
	}
	
	return ret;
}

COMP term(){
	COMP ret = fact();
	while(*p=='*'){
		p++;
		ret *= fact();
		if(abs(ret.real()) > 10000 || abs(ret.imag()) > 10000) throw 0;
	}
	return ret;
}

COMP expr(){
	COMP ret = term();
	while(*p=='+' || *p=='-'){
		char ope = *p++;
		if(ope=='+') ret += term();
		if(ope=='-') ret -= term();
		if(abs(ret.real()) > 10000 || abs(ret.imag()) > 10000) throw 0;
	}
	return ret;
}

int main(){
	COMP ret;
	while(cin>>buf){
		p = buf;
		try{
			ret = expr();
			if(ret.real() || !ret.imag()) cout << ret.real();
			if(ret.imag()>0 && ret.real()) cout << '+';
			if(ret.imag()) cout<<ret.imag()<<"i";
			cout << endl;
		}catch(...){
			cout<<"overflow"<<endl;
		}
	}
}