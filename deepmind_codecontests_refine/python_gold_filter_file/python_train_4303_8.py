t = int(input())
for _ in range(t):
  a,b  = [int(x) for x in input().split()]
  if(a<b):
    temp=a
    a=b
    b=temp
  diff = a-b
  if(diff==0):
    print('0 0')
  elif(diff==1):
    print('1 0')
  else:
    low = a//diff
    if(a - low*diff > 0.5*diff):
      low=low+1
    c = low*diff
    d = (low-1)*diff
    steps = abs(c-a)
    print(diff,steps)