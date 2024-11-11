n=int(input())
s=list(input())
ans=""
for i in s:
  q=ord(i)-65
  ans+=chr((q+n)%26+65)
print(ans)
