k,n,s,p = map(int,input().split())
x = (n+s-1)//s
x *= k
print((x+p-1)//p)


