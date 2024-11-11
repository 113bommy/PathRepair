k=[4,1,3,2,0,5]
a=int(input())
ans=0
for i in range(6):
    if a&(1<<i):
        ans+=1<<k[i]
print(ans)
