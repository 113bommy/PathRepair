#include<cstdio>
#include<cstring>
char s[60],t[60];
int n,m;
bool check(int k,char ch)
{
	for(int i=k;i<t+k;i++)
		if(s[i]!=t[i-k]&&s[i]!=ch)return 0;
	return 1;
}
int main()
{
	scanf("%s%s",s,t);
	n=strlen(s);
	m=strlen(t);
	for(int i=0;i<n;i++)
		if(check(i,' '))
		{
			for(int j=0;j<n;j++)
				if(s[j]=='?')s[j]='a';
			puts("s");
			return 0;
		}
	for(int i=n-1;i>=0;i--)
		if(check(i,'?'))
		{
			for(int j=i;j<i+m;j++)s[j]=t[j-i];
			for(int j=0;j<n;j++)
				if(s[j]=='?')s[j]='a';
			puts(s);
			return 0;
		}
	puts("UNRESTORABLE");
	return 0;
}
