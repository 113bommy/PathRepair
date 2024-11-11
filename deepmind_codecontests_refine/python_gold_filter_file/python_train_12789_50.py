O = input()
E = input()
z = ""

for s,t in zip(O,E):
  z+=s
  z+=t
  
if len(E)<len(O):
  z+=O[-1]

print(z)
