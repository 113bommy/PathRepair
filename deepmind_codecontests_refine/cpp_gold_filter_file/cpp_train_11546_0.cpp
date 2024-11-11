#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int a,b,mato[1000];
	vector<int> nums;
	while(scanf("%d%d",&a,&b),a,b){
		int res=0;
		nums.clear();
		for(int i=0;i<a;i++)scanf("%d",mato+i);
		for(int i=0;i<=a;i++)
			for(int j=0;j<=a;j++)
				nums.push_back(mato[i]*!!(i-a)+mato[j]*!!(j-a));
				
		sort(nums.begin(),nums.end());
		vector<int>::iterator it=nums.begin();
		while(it!=nums.end() && b>=*it){
			vector<int>::iterator itt=upper_bound(nums.begin(),nums.end(),b-*it);
			res=max(res,*it+++*--itt);
		}
		printf("%d\n",res);
	}
	return 0;
}