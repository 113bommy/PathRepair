def f(m,n):
    x=0
    for i in range(len(m)):
        if m[i]!=n[i]:
            x=x+1 
    return x
l=list(map(int,input().split()))
p=list(map(int,input().split()))
if f(l,p) ==3   :
    print("NO")
else:
    print("YES")