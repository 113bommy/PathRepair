test = [int(x) for x in input().split()]
a =test [0]
b =test [1]
c =test [2]

print(min(a+a+b+b, a+b+c , b+b+c+c, a+a+c+c))