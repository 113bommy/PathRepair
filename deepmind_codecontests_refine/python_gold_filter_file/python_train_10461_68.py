k,n,w=map(int,input().split())
s=0
for i in range(1,w+1):
    s=s+i
if s*k>n:
    print(s*k-n)
else:
    print(0)
