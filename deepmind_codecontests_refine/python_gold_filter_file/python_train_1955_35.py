def decomp(m):
    p2=0
    p5=0
    while m%2==0:
        m//=2
        p2+=1
    while m%5==0:
        m//=5
        p5+=1
    return p2,p5

n=int(input())
table=[[0]*50 for _ in range(50)]
ans=0
for i in range(n):
    a=input().split('.')
    if len(a)==1:
        ax=int(a[0]+'0'*9)
    else:
        ax=int(a[0]+a[1]+'0'*(9-len(a[1])))
    p2,p5=decomp(ax)
    if i!=0:
        for j in range(18-p2,50):
            ans+=sum(table[j][18-p5:])
    table[p2][p5]+=1

print(ans)