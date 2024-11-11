n=int(input())
a=sorted(list(map(int,input().split())))
f=0
ans=1
for i in range(0,len(a)):
    if a[i]>=ans:
        ans+=1
print(ans)