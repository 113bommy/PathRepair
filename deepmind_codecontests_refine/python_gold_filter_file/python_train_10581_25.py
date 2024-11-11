n, m = [int(i) for i in input().split()]
mini = -1
for i in range(n):
    a, b = [int(i) for i in input().split()]
    if a/b < mini or mini==-1:
        mini = a/b

print(mini*m)
