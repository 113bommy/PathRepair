n,m=input().split()
n=int(n)
m=int(m)
a=[list(map(int,input().split()))for i in range(n)]
black=0
for i in range(n):
    t=0
    while t<=2*(m-1):
        if a[i][t]==a[i][t+1]==0:
            black+=1
        t+=2
print(n*m-black)
