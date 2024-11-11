I=input
n=int
for i in range(int(input())):
  I();t=[];x=0
  for i,j in zip(map(n,I().split()[::-1]),I()[::-1]):
    for k in t:i^=k*(i^k<i)
    j=n(j);t.append(i*(j^1));x|=(i>0)&j
  print(x)