n = int(input())
ans = ''
while n > 0:
    n -= 1
    ans = chr(ord('a') + n % 26) + ans
    n //= 26
print(ans)
