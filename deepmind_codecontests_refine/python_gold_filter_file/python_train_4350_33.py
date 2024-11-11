n = int(input())
ans = ""
while n > 0:
    n -= 1
    ans += chr(97 + n % 26)
    n //= 26
print(ans[::-1])
