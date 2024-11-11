from itertools import permutations
ch=list(map(int,input().split()))
op=list(input().split())

def f(oper, x, y):
    if oper=="*":
        return (x*y)
    else:
        return (x+y)
ans=10**12
for a,b,c,d in permutations(ch):
    ans=min(ans, min(f(op[2], f(op[1], f(op[0],a,b), c), d), f(op[2], f(op[0],a,b),f(op[1],c,d))))
print(ans)
