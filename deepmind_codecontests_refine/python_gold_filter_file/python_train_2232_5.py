l=list(map(int,input().split()))
b=input()
ans=0
for i in range(4):
    ans+=l[i]*b.count(str(i+1))
print(ans)