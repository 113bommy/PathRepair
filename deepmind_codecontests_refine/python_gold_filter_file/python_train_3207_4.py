s = input()
l=len(s)
ans=[1]*l
for i in range(l-1):
    if s[i]==s[i+1]=="R":
        ans[i+2]+=ans[i]
        ans[i]=0
for i in range(l-1,1,-1):
    if s[i]==s[i-1]=="L":
        ans[i-2]+=ans[i]
        ans[i]=0
print(*ans)