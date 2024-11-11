d = int(input())
n = int(input())
a = [int(i) for i in input().split()]
s = 0
for i in a[:-1]:
    s += d-i
print(s)
