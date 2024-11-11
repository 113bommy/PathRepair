a=int(input())
n=a
i=2
fc=[]
while i*i<=a:
  while a%i==0:
    a//=i
    fc.append(i)
  i+=1
if a>1:
  fc.append(a)
print(str(n)+": "+" ".join(str(b) for b in fc))
