n=int(input())
b=[]
a=list(map(int, input().split()))
for _ in range(1,len(a)-1):
    x=list(a)
    x.pop(_)
    c=[]
    for _ in range(len(x)-1):
        c.append(x[_+1]-x[_])
    b.append(max(c))
print(min(b))