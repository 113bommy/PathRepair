N,X = map(int, input().split())
t = [0]*(N+1)
h = [0]*(N+1)
h[0]=1
t[0]=1
for i in range(1, N+1):
    h[i]=2*(h[i-1])+3
    t[i]=2*(t[i-1])+1
def find(n, x):
    if n==0:
        return 0 if x<=0 else 1
    elif x<=1+h[n-1]:
        return find(n-1, x-1)
    else:
        return t[n-1]+1+find(n-1, x-2-h[n-1])
print(find(N,X))
