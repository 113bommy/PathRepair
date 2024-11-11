a=input()
c=a.lower().strip(' ?')

b=c[::-1]




if b[0] in 'aeiouy':
  print("YES")
else:
  print("NO")