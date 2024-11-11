n,k = map(int,input().split())
if n*(n-1) <= k*2:
    print('no solution')
else:
    x = 11
    for i in range(n-1):
        print(1,x)
        x+=3
    print(1,x-5)
   
        