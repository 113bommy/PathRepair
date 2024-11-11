x=input().split()
y=list(set(x))
print(y[x.count(y[0])-1])