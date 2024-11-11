n=int(input())
s=input()
x=(s.count('R'))*(s.count('G'))*(s.count('B'))
for i in range(1,(n-1)//2+1):
  for j in range(n-i*2):
    if len(set([s[j],s[j+i],s[j+i+i]]))==3:
      x-=1
print(x)