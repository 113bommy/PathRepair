n,k = map(int,input().split())
a = list(map(int,input().split()))
s = [False]*(k+1)
for i in range(k+1):
  for aj in a:
    if i - aj >=0:
      if s[i-aj] == False:
        s[i] = True
        break
if s[k]==True:
  print("First")
else:
  print("Second")