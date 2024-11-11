n = input()

if int(n) < 10:
  print(n)
else:
  ans = 1
  for i in n:
    ans *= int(i)
  
  for i in range(len(n)-1):
    c = 1
    cur = str(int(n[:i+1])-1)
    cur += "9"*(len(n)-i-1)
    #print(cur)
    cur = str(int(cur))
    for j in cur:
      c *= int(j)
    ans = max(ans, c)
  print(ans)
