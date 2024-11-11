s1 = input()
s2 = input()

x = len(s1)
y = len(s2) 

i = x -1
j = y -1
c = 0
flag = True

while flag and i >= 0 and j >= 0:
  if s1[i] != s2[j]:
    flag = False
    c += (i+1)
    c += (j+1)
    break
  i -= 1
  j -= 1

if flag:
  if i < 0:
    c += (j+1)
  else:
    c += (i+1)

print(c)