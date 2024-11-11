n=int(input())
s=list(input())
a=""
for c in s:
  a+=chr((ord(c)-ord("A")+n)%26+ord("A"))
print(a)
  
