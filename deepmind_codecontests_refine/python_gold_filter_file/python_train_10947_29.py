t = int(input())
for i in range(0,t):
  n = int(input())
  count = 0
  ans = n
  while(ans!=1):
    if(ans%2 == 0):
      ans = ans//2
      count = count+1
    elif(ans%3 == 0):
      ans = (2*(ans//3))
      count = count+1
    elif(ans%5 == 0):
      ans= 4*(ans//5)
      count= count+1
    else:
      break
  if(ans == 1):
    print(count)
  else:
    print('-1')