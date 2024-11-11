n, m = map(int, input().split())
res = 0
mx = (n-1)*n//2
mn = 0
if n&1:
    mn = (n//2)*(n//2+1)
else:
    mn = n*n//4
for i in range(m):
    x, d = map(int, input().split())
    res += x*n
    if d > 0:
        res += mx*d
    else:
        res += mn*d
print('%.10f'%(res/n))
