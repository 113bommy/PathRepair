a = input()
x = []
for i in a:
  if i.isupper():
      i = i.lower()

  if i in ['a','o','y','e','u','i']: 
    continue
  else:
    x.append('.')
    x.append(i)
s = ''.join(x)     

print(s)    