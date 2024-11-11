n = int(input())
x = 0
s = list(input())
for i in s:
    if i == '+':
        x+=1
    else:
        x = max([0, (x-1)])
print(x)