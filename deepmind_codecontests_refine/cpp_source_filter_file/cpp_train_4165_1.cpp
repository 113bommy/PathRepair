#include <iostream>
using namespace std;
int n,a,total=0,kisuusaisyou=101;
int main(){
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>n;
		if(kisuusaisyou>n&&n%2==1)kisuusaisyou=n;
		total+=n;
	}
		if(total%2=-1){cout<<(total-kisuusaisyou)/2<<endl;
	}else{
		cout<<total/2<<endl;
	}
    return 0;
}
