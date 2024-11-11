#include <stdio.h>
#include <vector>
using namespace std;
int RB[11][11],j,N;bool used[11][11];vector<int>a,x;
void dfs(int here, int prev, int cost) {used[here][prev]=used[prev][here]=0;x.push_back(here);for (int i=1,k=0;i<=N;i++) {if (used[here][i] && RB[here][i]) k++,dfs(i,here,cost+RB[here][i]); if (!k) if (j<cost) j=cost,a=x;} x.pop_back();used[here][prev]=used[prev][here]=1;}
int main() {int i,k,f;for (i=0;i<11;i++) for (j=0;j<11;used[i][j++]=1);while (1) {a.clear(),x.clear();scanf("%d %d",&N,&k);if (!N && !k) return 0;for (i=1;i<=N;i++) for (j=1;j<=N;RB[i][j++]=0);while (k--) {scanf("%d %d %d",&i,&j,&f);RB[i][j]=RB[j][i]=f;}for (i=1,j=0;i<=N;i++) dfs(i,i,0);printf("%d\n",j);for (printf("%d",a[0]),i=1,j=a.size();i<j;printf(" %d",a[i++]));puts("");}}