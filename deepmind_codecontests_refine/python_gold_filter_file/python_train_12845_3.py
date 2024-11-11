n,k = map(int,input().split())
if n*(n-1) <= k*2:
    print('no solution')
else:
    for i in range(n):
        print(0,i)