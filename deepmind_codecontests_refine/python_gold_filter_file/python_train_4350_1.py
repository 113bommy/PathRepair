n=int(input())
ans=''
while n:
  ans+=chr((n-1)%26+ord('a'))
  n=(n-1)//26
print(ans[::-1])