n = int(input())
ans = 0
z = len(str(n))
while n >= 1:
    x = 10 ** (z-1)
    ans += (n-x+1)*len(str(n))
    n = x-1
    z -= 1
print(ans)