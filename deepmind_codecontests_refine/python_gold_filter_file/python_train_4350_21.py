n = int(input())
ans = ''
while n:
  n -= 1
  ans += chr(ord('a') + n % 26)
  n //= 26
print(ans[::-1])