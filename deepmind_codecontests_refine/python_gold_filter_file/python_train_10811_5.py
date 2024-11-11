input()
s =input()
a = [0]
n = 0
for i in s :
  if i == 'I':
    n +=1
  else :
    n-=1
  a.append(n)
print(max(a))
    