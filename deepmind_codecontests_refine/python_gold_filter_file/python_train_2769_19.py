a,b=map(int,input().split())
c=min(a,b)
S=1
for i in range(1,c+1):
    S*=i
print(S)
