m = [int(x) for x in input().split()]
[a, b, c, d] = m
x = max([3*a//10, a - a*c//250])
y = max([3*b//10, b - b*d//250])
if x==y:
    q = 'Tie'
elif x > y:
    q = 'Misha'
else:
    q = 'Vasya'
print(q)