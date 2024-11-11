n = int(input())

ans = ""
while n:
    n -= 1
    ans = chr(97 + n % 26) + ans
    n //= 26

print(ans)
