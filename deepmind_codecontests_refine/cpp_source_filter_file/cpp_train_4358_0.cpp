//#pragma GCC optimize(2)
//#include<bits/stdc++.h>
//using namespace std;
//stack <char> q;
//char a[1200000];
//inline int read() {
//	int X=0,w=0;
//	char ch=0;
//	while(!isdigit(ch)) {
//		w|=ch=='-';
//		ch=getchar();
//	}
//	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
//	return w?-X:X;
//}
//int main() {
//	freopen("fusion.in","r",stdin);
//	freopen("fusion.out","w",stdout);
//	scanf("%s",a+1);
//	int m;
//	cin>>m;
//	for(int i=1; i<=m; i++) {
//		int x,y;
//		x=read();
//		y=read();
//		while(!q.empty()) q.pop();
//		for(int j=x; j<=y; j++) {
//			if(q.empty()) {
//				q.push(char(a[j]));
//				continue;
//			}
//			char w=q.top();
//			char at=a[j];
//			q.push((char)a[j]);
//			if(w==at) {
//L1:
//				;
//				if(w=='z') {
//					q.pop();
//					q.pop();
//				} else {
//					q.pop();
//					q.pop();
//
//					at=(char)w+1;
//					if(q.empty()) {
//						q.push(at);
//						continue;
//					}
//					w=q.top();
//					q.push(at);
//					if(at==w) goto L1;
//				}
//			}
//		}
//		if(q.empty()) puts("Yes");
//		else puts("No");
//	}
//	return 0;
//}








































#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
char s[560000];
int n,m;
int to[560000][30],nxt[560000][30];
inline int read() {
	int ret=0;
	char c=getchar();
	while((c>'9')||(c<'0'))c=getchar();
	while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ret;
}
void pre() {
	for(int i=1; i<=n+2; i++) {
		for(int j=0; j<=26; j++) to[i][j]=n+2;
		for(int j=0; j<=19; j++) nxt[i][j]=n+2;
	}
	for(int i=n; i; i--) {
		to[i][s[i]]=i+1;//更新自己这一位
		for(int j=s[i]+1; j<=26; j++) to[i][j]=to[to[i][j-1]][j-1]; //从k变到j（合并操作）
		nxt[i][0]=to[i][26];//记录消除完的情况
		for(int j=1; j<20; j++) nxt[i][j]=nxt[nxt[i][j-1]][j-1]; //更新多段消除完的情况
		for(int j=0; j<26; j++) if(to[i][j]==n+2) to[i][j]=to[nxt[i][0]][j]; //如azzabcd…即对于前面没有算出东西的情况中，先消除掉一部分再进行计算。
	}
}
bool check(int l,int r) {
	for(int i=19; i>=0; i--) {
		if(nxt[l][i]==r+1) return true;
		if(nxt[l][i]<=r) l=nxt[l][i];
	}
	return false;
}
int main() {
// 	freopen("fusion.in","r",stdin);
// 	freopen("fusion.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; i++) s[i]-='a';
	pre();
	w=read();
	while(m--) {
		int l=read(),r=read();
		if(check(l,r)) puts("Yes");
		else puts("No");
	}
	return 0;
}