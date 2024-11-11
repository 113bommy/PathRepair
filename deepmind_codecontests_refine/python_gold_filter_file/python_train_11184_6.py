a,b=map(int,input().split())
def work(a,b):
    c=int(float(b*b-a*a)**0.5)
    if c*c+a*a==b*b:
        return [a,c]
    return []
def get(a):
    return list(work(i,a) for i in range(1,a) if len( work(i,a) )>0)
A=get(a)
B=get(b)
for [a,b] in A:
    for [c,d] in B:
        if a*c==b*d and b!=d:
            print("YES")
            print(0,0)
            print(-a,b)
            print(c,d)
            break
    else:
        continue
    break
else:
     print("NO")
