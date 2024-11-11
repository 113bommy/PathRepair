import itertools as t;N=input();X=[]
for i in range(10):X+=list(t.product('357',repeat=i))
print(sum(len(set(i))>2and int(''.join(i))<=int(N)for i in X))