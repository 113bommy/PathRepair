s1=input()
s2=input()
a=[[0]*(len(s2)+1) for i in range(len(s1)+1)]
res=''
for i in range(1,len(s1)+1):
  for j in range(1,len(s2)+1):
    if s1[i-1] == s2[j-1]:
      a[i][j] = a[i-1][j-1] + 1
    elif a[i-1][j] >= a[i][j-1]:
      a[i][j] = a[i-1][j]
    else:
      a[i][j] = a[i][j-1]
i=len(s1)
j=len(s2)
while i>0 and j>0:
  if a[i][j] == a[i-1][j]:
    i -= 1
  elif a[i][j] == a[i][j-1]:
    j -= 1
  else:
    res = s1[i-1] + res
    i -= 1
    j -= 1   
print(res)