n=int(input())
x=[int(q) for q in input().split()]
print(n-1)
for i in range(n-1):
    s=min(x[i:])
    y=x[i:]
    x[i],x[i+y.index(s)]=x[i+y.index(s)],x[i]
    print(i,i+y.index(s))