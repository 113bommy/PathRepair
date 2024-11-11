import itertools
n=input()
c=[0,0,6,36,150,540,1806,5796,18150]
b=len(list(a for a in itertools.product(["3","5","7"],repeat=len(n))if len(set(a))==3 and int("".join(a))<=int(n)))
print(sum(c[:len(n)-1])+b)