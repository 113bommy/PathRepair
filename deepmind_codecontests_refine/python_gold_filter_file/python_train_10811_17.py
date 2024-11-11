n=int(input())
s=input()
a=0
b=0
for i in range(n):
  if s[i]=="I":
    a=a+1
    if a>b:
      b=a
  else:
    a=a-1
print(b)