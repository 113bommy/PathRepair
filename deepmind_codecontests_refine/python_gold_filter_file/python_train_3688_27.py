n = int(input())
r = [int(i) for i in input().split()]
a, b = [int(i) for i in input().split()]


print(sum(r[a-1:b-1]))
