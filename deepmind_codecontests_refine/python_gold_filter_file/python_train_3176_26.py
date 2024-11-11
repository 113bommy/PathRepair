n,t=map(int,input().split())
tag=0
for i in range(10**(n-1),10**n):
    if i%t==0:
        tag=1
        print(i)
        break
if tag==0:
    print(-1)
