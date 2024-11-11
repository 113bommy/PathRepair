n,s=map(int,input().split())
c=s//n
d=s%n
print(c if d==0 else c+1)