n = int(input())
ans = 0
i = 2

while n>1 and i*i<=n:
  if n % i == 0:
    c = 0
    while n % i == 0:
      n = n / i
      c = c + 1
    Y=1
    U=2
    while c>=Y:
      ans=ans+1
      Y=Y+U
      U=U+1

  i = i + 1
      
    
if n > 1:
  ans = 1 + ans

print(ans)