a=int(input())
b=input()
c=list(map(int,input().split()))
d={'h':1,'a':2,'r':3,'d':4}
e=[10**20,0,0,0,0]
for f,g in zip(c,b):
    if g in d:
        e[d[g]]=min(e[d[g] - 1],e[d[g]]+f)
print(e[4])
