n = int(input())
ans = ''
while n:
  ans = chr((n-1)%26+ord('a')) + ans
  n = (n-1) // 26
print(ans)