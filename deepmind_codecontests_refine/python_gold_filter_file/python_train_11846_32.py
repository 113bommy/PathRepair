n=int(input())
m=100
ans=0
while n>m:
    m+=m//100
    ans+=1
print(ans)