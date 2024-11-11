a,b,n = map(int,input().split())
r=(b-(10*a)%b)%b
if r>9:
    print(-1)
else:
    print(str(a)+str(r)+(n-1)*"0")

