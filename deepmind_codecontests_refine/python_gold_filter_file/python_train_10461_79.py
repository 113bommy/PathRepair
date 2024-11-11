k,n,w=map(int,input().split())
j=0
for i in range(1,w+1):
    j=j+i*k
if j>n:
    print(j-n)
else:
    print(0)