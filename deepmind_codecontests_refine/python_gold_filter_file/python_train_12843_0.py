n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
for x in a:
    i=str(x)
    if((i.count('4')+i.count('7'))<=k):
        c=c+1
print(c)
