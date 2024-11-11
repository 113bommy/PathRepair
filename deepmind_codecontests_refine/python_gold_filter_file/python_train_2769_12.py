a,b=map(int, input().split())
c=min(a,b)
f=1
for i in range(1,c+1):
    f*=i
print(f)