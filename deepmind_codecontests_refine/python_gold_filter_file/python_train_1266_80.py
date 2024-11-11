n=int(input())
ans=0;
p=1;
k=4;
for i in range(n):
    ans=ans+p;
    p=k;
    k=k+4;
print(ans)    
