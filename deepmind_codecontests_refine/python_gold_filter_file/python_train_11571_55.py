n,v=[int(x) for x in input().split()]
s=v
if v>=(n-1):
    print(n-1)
else:
    t=n-v
    res=t*(t+1)//2
    print(res+(v-1))