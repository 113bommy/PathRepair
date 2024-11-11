n, m = input().split(' ')
n, m = int(n), int(m)
s = 0
for i in range(m):
    x, d = input().split(' ')
    x, d = int(x), int(d)
    s = s + n*x
    if d >= 0:
        s = s + d*((n*(n-1))//2)
    else:
        s = s + 2*d*((((n-1)//2)*((n-1)//2+1))//2)
        if n % 2 == 0:
            s = s + d*(n//2)
print(s/n)
