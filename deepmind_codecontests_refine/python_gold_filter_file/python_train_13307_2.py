from itertools import combinations
n=int(input())
s=[input()[0] for _ in range(n)]
a=[]
for i in ['M','A','R','C','H']:
  a+=[s.count(i)]
ans=0
for i in combinations(a,3):
  ans+=i[0]*i[1]*i[2]
print(ans)