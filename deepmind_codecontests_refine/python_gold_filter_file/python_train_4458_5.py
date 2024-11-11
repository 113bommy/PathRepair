n=int(input())
s=0
for _ in range(n):
  a,b=input().split()
  if str(b)=="JPY":
    s+=int(a)
  else:
    s+=float(a)*380000
print(s)