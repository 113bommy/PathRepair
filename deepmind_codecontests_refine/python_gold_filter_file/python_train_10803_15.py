n=int(input())
ans=0
i=2
while i*i<=n:
    cnt=0
    while n%i==0:
        n//=i
        cnt+=1
    j=0
    # print(i,cnt)
    for k in range(1,cnt+1):
        if (k*(k+1))//2<=cnt:
            j=max(j,k)
    ans+=j
    i+=1
# print('n',n)
if n>1:
    ans+=1
print(ans)
