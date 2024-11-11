m,d=map(int,input().split())
ans=chk=0
for i in range(1,m+1):
    for j in range(22,d+1):
        if (j%10!=1 and j//10>1 and j%10>1 and i==((j//10)*(j%10))):
            ans+=1
print(ans)
