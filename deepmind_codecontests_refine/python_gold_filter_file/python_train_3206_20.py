a,b,k = map(int,input().split())
if k > a:
    print(0,max(a+b-k,0))
else:
    print(a-k,b)