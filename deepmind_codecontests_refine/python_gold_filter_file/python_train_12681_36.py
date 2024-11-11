s = input()
t = input()

n = len(t) + 1
m = len(s) + 1

data = [[0 for _ in range(n)] for _ in range (m)]

ans = ''
for i in range(1,m) :
  for j in range(1,n) :
    if s[i-1] == t[j-1] :
      data[i][j] = data[i-1][j-1] + 1
    else :
      data[i][j] = max(data[i-1][j] , data[i][j-1])

i = len(s)
j = len(t)

while i>0 and j>0 :
  if data[i][j] == data[i][j-1] :
    j -= 1
  elif data[i][j] == data[i-1][j] :
    i -= 1
  else :
    ans = s[i-1] + ans
    i -= 1
    j -= 1
    
print(ans)