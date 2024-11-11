l = [int(i) for i in input().split()]
k = l[0]
n = l[1]
w = l[2]
y = [k]
for i in range(1,w):
    x = k + (k * i)
    y.append(x)
if n >= sum(y):
    print("0")
else:
    print(sum(y)-n)