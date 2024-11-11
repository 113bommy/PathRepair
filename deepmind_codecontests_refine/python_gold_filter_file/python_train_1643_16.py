n = int(input())
X = input()

def goes_to_zero(n):
  cnt = 0
  while(n > 0):
    n %= bin(n).count('1')
    cnt += 1
  return cnt
  
c1 = X.count('1')
xint = int(X,2)
xtp = xint % (c1 + 1)
if (c1 - 1) == 0:  
  xtm = 0
else:
  xtm = xint % (c1 - 1)
  
for i in range(n)  :
  if X[i] == '0':
    print(goes_to_zero( (xtp + pow(2,n-1-i,(c1+1))) % (c1+1) ) + 1)
  else:
    if (c1-1) == 0:
      print(0)
    else:
      print(goes_to_zero( (xtm - pow(2,n-1-i,(c1-1)) ) % (c1-1) ) +1)