import math
def composite(p):
    s = math.sqrt(p) #better than going all the way up to p, check all possible divisors
    for i in range(2,int(s)+1):
        if(p%i == 0):
            return False
    return True
n = int(input())
flag = True
for i in range(2,n):
  for j in range(2,n):
      if(not composite(i) and not composite(j)):
            if(j+i != n):
              flag = True
            else:
              flag = False
              break
  if(not flag):
    break
print(i, " ",j)