 #include <cstrdio>

using namespace std;
int a,d;
int main(){
	scanf("%d%d",&a,&d);
	if(a > 8 ||  d > 8)printf(":(");
	else puts("Yay!");
	return 0;
}