n = int(input())
x = [input() for i in range(3)]
c=0
for i in range(n):
    c+=len(set([x[0][i],x[1][i],x[2][i]]))-1
print(c)