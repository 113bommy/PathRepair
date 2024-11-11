n = int(input())
k = [int(i) for i in input().split()]
a, b = [int(i) for i in input().split()]

print(sum(k[a-1:b-1]))
