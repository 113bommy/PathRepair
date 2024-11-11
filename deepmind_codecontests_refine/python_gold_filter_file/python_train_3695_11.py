x=int(input())
k=(input())

s=[int(n) for n in (k)]
a=s.count(0)
b=s.count(1)
print(abs(a-b))