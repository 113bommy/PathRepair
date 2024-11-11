n = int(input())
s=''
while n!=0:
  n-=1
  tmp=n%26
  s=chr(96+tmp+1)+s
  n//=26
print(s)