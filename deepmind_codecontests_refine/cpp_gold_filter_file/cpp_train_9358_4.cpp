#include <iostream>
 
using namespace std;
 
int main()
{
	int total,books;
	while(true){
		cin>>total;
		if(total==0){
			break;
		}
	for(int i=1;i<=9;i++){
	cin>>books;
	total-=books;
	}
	cout<<total<<"\n";
	}

    return 0;
}