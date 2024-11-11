
n = int(input())
l = [int(x) for x in input().split()]
l2 = list(range(n))
for i in range(n):
    a = l[i]
    l2[a-1] = i+1

for m in l2:
    print(m,end=' ')

