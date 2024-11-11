#include <include>
using namespace std;
int main() {
int n1;cin>>n1;
n1=n1%100;
 if(n1==3)
   cout<<"bon";
 else if(n1==0||n1==1||n1==6||n1==8)
   cout<<"pon";
 else
   cout<<"hon";}
  
	return 0;
}