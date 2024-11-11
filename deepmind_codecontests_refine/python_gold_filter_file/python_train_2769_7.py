a,b=map(int,input().split())
c=min(a,b)
s=1
for i in range(1,c+1):
    s*=i
print(s)