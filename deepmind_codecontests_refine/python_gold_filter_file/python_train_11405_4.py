n,m=map(int,input().split())
M=[]
for i in range(m):
    l=list(map(int,input().split()))
    M.append(l)
profit=0
for i in range(1,n+1):
    time=10000
    price=0
    for j in range(m):
        if(i>=M[j][0] and i<=M[j][1] and time>M[j][2]):
            if(time==M[j][2]):
                price=max(price,M[j][3])
            else:
                price=M[j][3]
            time=M[j][2]
    profit+=price
print(profit)
