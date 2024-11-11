x=int(input())
t=0
for i in range(1,x+1):
  if i%3!=0 and i%5!=0:
    t+=i
print(t)