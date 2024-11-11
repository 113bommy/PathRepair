def f(l):
    n  = len(l)
    rl = [0]*n
    rm = l[-1]
    for i in range(n-2,-1,-1):
        rl[i] = max(rm+1-l[i],0)
        if l[i]>rm:
            rm = l[i]
    return rl 

_ = input()     #1e5
l = list(map(int,input().split()))
print(*f(l))
