n=int(input())
s=str(input())
ans=int(s)
mid=n//2
for i in range(mid,-1,-1):
    if s[i+1]=='0':
        continue;
    ans=min(ans,int(s[:i+1])+int(s[i+1:n]))
    break
for i in range(mid,n-1):
    if s[i]=='0':
        continue
    ans=min(ans,int(s[:i])+int(s[i:n]))
    break
print(ans)