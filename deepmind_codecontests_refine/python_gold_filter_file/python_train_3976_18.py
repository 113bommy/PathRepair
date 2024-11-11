from math import ceil
t = int(input())
for i in range(t):
    a, b, n = map(int, input().split())
    if n==0:
      if a>b:
        print('1')
      else:
        print('0')
    elif a==b:
      print(ceil(n/2))
    elif a>b:
      print(min(ceil((a+n-b)/2),n+1))
    else:
      g=a
      a+=(b-a)
      n-=(b-g)
      print(max(ceil(n/2),0))