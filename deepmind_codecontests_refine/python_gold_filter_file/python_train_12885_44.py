a=input()
b=input()
c=0
for i in range(len(a)):
  if a[i]==b[i]:
    c=c+1
print(len(a)-c)