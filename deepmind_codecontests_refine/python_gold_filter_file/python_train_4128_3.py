n=int(input())
ans=0
for a in range(1,n):
    for b in range(a+1 ,n):
        c=a^b
        if b<=c<=n and c<a+b:
            ans+=1
print(ans)