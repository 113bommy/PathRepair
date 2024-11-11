x=list(map(int,input().split()))
y=str(input())
ans=0
for i in y:
    ans+=x[int(i)-1]
print(ans)