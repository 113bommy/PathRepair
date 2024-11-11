#making triangle
a, b, c = sorted(list(map(int,input().split())))
result = 0
if c < (a+b) :
    result = 0
else:
    result = c - (a+b) + 1
print(result)