a,b,c,d=map(int,input().split())
p=min(a,c,d)
a-=p
q=min(a,b)
print(256*p+32*q)