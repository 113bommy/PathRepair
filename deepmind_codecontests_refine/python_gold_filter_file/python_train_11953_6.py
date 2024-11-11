n=int(input())
a,b,c=input(),input(),input()
ct=0
for i in range(n):
  if a[i]==b[i]==c[i]:ct+=0
  elif a[i]==b[i] or b[i]==c[i] or c[i]==a[i]:ct+=1
  else:ct+=2
print(ct)