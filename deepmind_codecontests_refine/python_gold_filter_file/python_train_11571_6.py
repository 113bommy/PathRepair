n,v=map(int,input().split())
if n-1<=v:
    print(n-1)
else:
    e=(n-v-1)*(n+2-v)//2
    print(e+v)
