s=input()
a=0
b=0
for i in s:
  if i in "ATGC" :
    a+=1
  else:
    b=max(a,b)
    a=0
print(max(a,b))