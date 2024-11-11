def toi(n):
  pre = n - 1
  ans =  1 
  for i in range(2,2000):
    c = 0
    if pre%i==0:
      while pre%i == 0:
        c +=1
        pre//=i
      ans*=(i-1)*(i**(c-1))
    i+=1
  return int(ans)
  
n = int(input())
print(toi(n))