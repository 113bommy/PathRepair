N=int(input())
keta=1
a=26
ans=""
while N>0:
  N-=1
  ans+=chr(ord('a')+N%26)
  N=N//26
print(ans[::-1])