n=int(input())
y=list(map(int, input().split()))
a=y[0]+y[1]+y[2]+y[3]
rank=1 
for i in range(0,n-1):
    x=list(map(int, input().split())) 
    b=x[0]+x[1]+x[2]+x[3]
    if b>a:
      rank=rank+1
print(rank)
