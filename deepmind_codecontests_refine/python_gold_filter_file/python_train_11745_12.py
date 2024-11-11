N,X=map(int,input().split())

a,p=[1],[1]

for i in range(N):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

def solve(n,x): #n,x
    if n==0:
        if x<=0:
            return 0
        else:
            return 1
    elif x<=1+a[n-1]:
        return  solve(n-1,x-1)
    else:
        return p[n-1]+1+solve(n-1,x-2-a[n-1])

print(solve(N,X))
