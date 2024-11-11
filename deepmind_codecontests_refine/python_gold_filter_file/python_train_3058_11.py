#for _ in range(int(input())):
a,b,n=map(int,input().split())
f=0
for i in range(10):
    x=int(str(a)+str(i))
    if x%b==0:
        f=1
        break
if f==0:
    print(-1)
else:
    x=int(str(x)+"0"*(n-1))
    print(x)