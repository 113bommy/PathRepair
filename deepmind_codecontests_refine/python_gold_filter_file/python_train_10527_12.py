n,k = map(int,input().split())
flag = True
mx = n*k
for b in range(1,k):
    if n%b == 0:
        a = n//b
        x = a*k + b
        if x < mx:
            mx = x
print(x)
    