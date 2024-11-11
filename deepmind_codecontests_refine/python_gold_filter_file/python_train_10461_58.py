k,n,w=map(int,input().split())
s=0
for i in range(1,w+1):
    s=s+i*k
if(s-n>=0):
    print(s-n)
else:
    print(0)