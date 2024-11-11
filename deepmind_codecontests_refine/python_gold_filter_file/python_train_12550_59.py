n, c = [int(i) for i in input().split()]
list1 = [int(i) for i in input().split()]
a = 1
for i in range(n-1):
    if list1[i+1]-list1[i] <= c:
        a += 1
    else:
        a = 1
print(a)