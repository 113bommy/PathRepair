n,k=map(int,input().split(' '))
h=list(map(int,input().split(' ')))
node=[0]*n
for i in range(1,n):
    x=[abs(h[i]-h[i-m])+node[i-m] for m in range(1,min(i+1,k+1))]
    node[i]=min(x)
print(node[-1])