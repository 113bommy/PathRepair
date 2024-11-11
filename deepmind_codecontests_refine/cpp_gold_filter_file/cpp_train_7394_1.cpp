#include <iostream>
using namespace std;
int main(){
	int a,b,x;
	char op;
	do{
	cin>>a>>op>>b;
	switch(op){
	case '+':cout<<a+b<<endl;
	break;
	case '-':cout<<a-b<<endl;
	break;
	case '*':cout<<a*b<<endl;
	break;
	case '/':cout<<a/b<<endl;
	break;
	}
	}while(op!='?');
	return 0;
}