n = int(input())
s = ''
while n > 0:
  n-=1
  s += chr(ord('a') + n%26)
  n//=26
 
print(s[::-1])