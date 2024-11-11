n,s=map(int,input().split())
ans=0
i=n
while i>0:
    ans+=s//i
    s%=i
    i-=1
print(int(ans))