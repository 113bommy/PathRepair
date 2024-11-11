n,t=map(int,input().split())
p=10**(n-1)
ost=10**n
oz=0
for i in range(p,ost):
    if i%t==0:
        print(i)
        oz=1
        break
if oz==0:
    print(-1)