p=int(input())
t=0
n=100
while n<p:
  n+=n//100
  t+=1
print(t)