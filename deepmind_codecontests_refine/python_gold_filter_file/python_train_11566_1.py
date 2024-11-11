n=int(input())
X=[int(x) for x in input().split(" ")]
p=[]
b=[X[-1]]
print(X.count(1))
for i in range(1,n):
  if (X[i]==1):

    p.append(X[i-1])
p.extend(b)
print(" ".join(str(v) for v in p))