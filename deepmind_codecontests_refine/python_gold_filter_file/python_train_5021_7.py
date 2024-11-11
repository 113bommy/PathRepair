n=int(input())
s=input()
bal=0;ans=0
for i in s:
    if i=="(":
        bal+=1
    else:
        bal-=1
        if bal<0:
            ans+=2
if bal!=0:
    ans=-1
print(ans)