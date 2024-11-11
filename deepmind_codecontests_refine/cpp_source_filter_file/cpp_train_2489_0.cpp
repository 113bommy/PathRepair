#include<stdio.h>
#include<queue>
int main(){
	std::queue<int> q;
	int w,h,f[484],i,j,d[]={22,0,-1,0,1,0,-22},a,b,t,x,z;
	char p[15];
	for(;scanf("%d%d ",&h,&w),h;){
		for(j=0;j<w+2;j++)f[j]=f[j-~h*22]=-9;
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				f[x=i*22+j]=-1;
				switch(getchar()){
					case'#':--f[x];break;
					case'A':a=x;break;
					case'B':b=x;break;
				}
			}
			f[i*22]=f[i*22-~w]=-9;
			getchar();
		}
		
		f[a]=t=0;
		q.push(0);
		for(q.push(a);q.size()>1;){
			a=q.front();
			q.pop();
			if(a){
				for(i=0;i<7;i+=2)
					if(f[x=a+d[i]]==-1)
						f[x]=t,
						q.push(x);
			else
				++t,q.push(0);
		}
		q.pop();
		scanf("%s",p);
		for(a=t=0;!a;){
			x=b;
			z=0;
			for(i=0;!a&&p[i];i++){
				t++;
				f[j=b+d[p[i]-'2']]>-3?b=j:0;
				f[b]>=0&&t>=f[b]?a=b:0;
				f[b]>=0&&++z;
			}
			!z&!a&!p[i]&b==x&f[b]<0&&--a;
		}
		printf(a<0?"impossible\n":"%d %d %d\n",t,a/22-1,a%22-1);
	}
}