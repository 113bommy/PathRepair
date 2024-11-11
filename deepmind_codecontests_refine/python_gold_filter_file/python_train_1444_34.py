n = int(input())
s = int(input())
x = int(n**0.5)+1
def dsum(x,t):
  ret = 0
  while x>0:
    ret += x%t
    x //= t
  return ret
for i in range(2,x+1):
  if dsum(n,i) == s:
    print(i)
    exit()
for i in range(x,0,-1):
  if (n-(s-i))%i == 0:
    digit = (n-(s-i))//i
    if 0 < i < digit and 0 <= s-i < digit:
      print((n-(s-i))//i)
      exit()
if n == s:
  print(n+1)
  exit()
print(-1)