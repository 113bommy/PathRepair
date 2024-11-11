#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define L 503

struct move {
	int x,y,tx,ty;
};
int n,m,r;
int num[L][L];
bool even[L];
vector<move>ans;

int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<m;j++) {
			scanf("%d",&r);
			num[i][j]+=r;
			if(num[i][j]%2==1) {
				num[i][j]--,num[i][j+1]++;
				ans.push_back((move){i,j,i,j+1});
			}
		}
		scanf("%d",&r);
		num[i][m]+=r;
		if(num[i][m]%2==1) {
			if(i==n) continue;
			num[i][m]--,num[i+1][m]++;
			ans.push_back((move){i,m,i+1,m});
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d %d %d\n",ans[i].x,ans[i].y,ans[i].tx,ans[i].ty);
	return 0;
}