n,m,d = map(int,input().split())
c = 0
if d!=0:
    c = (n-d)*2
else:
    c = n
print(c/n/n*(m-1))
