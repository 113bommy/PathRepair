n,x = map(int,input().split())
a,p = [1],[1]
for i in range(n):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

def calc(n,x):
    if n==0:
        return 1 if x>0 else 0
    else:
        if x>a[n-1]+1:
            return p[n-1]+1+calc(n-1,x-2-a[n-1])
        else:
            return calc(n-1,x-1)
print(calc(n,x))