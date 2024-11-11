'''n = int(input())'''
n, k = [int(x) for x in input().split()]
l = [int(x) for x in input().split()]
l.sort()
c = 0
i = 2
while(i < n):
    if l[i] + k <= 5:
        c += 1
    i+=3
print(c)

