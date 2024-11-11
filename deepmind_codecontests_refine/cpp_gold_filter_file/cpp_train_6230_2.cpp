#include <bits/stdc++.h>
using namespace std;
int main(void)
{
char s[128];
int i, len;
scanf("%s", s);
len = strlen(s);
for(i = 1;i < len;++i)
if('A'==s[i-1]&&'C'==s[i])
{
puts("Yes"); return 0;
}
puts("No");
return 0;
}