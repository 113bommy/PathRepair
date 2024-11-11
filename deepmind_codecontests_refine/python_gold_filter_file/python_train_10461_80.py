a,b,c=map(int,input().split())
s=0
for i in range(1,c+1):
    s=s+i*a
if s>b:
    print(s-b)
else:
    print(0)