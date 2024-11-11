n,x = map(int,input().split())
cnt = 0
while n > 0 and x > 0:
    if x >= 2**(n+1)-1:
        cnt += 2**n
        x -= (2**(n+1)-1)
    else:
        x -= 1
    n -= 1
if x >= 1:
    cnt += 1
print(cnt)