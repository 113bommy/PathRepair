n = int(input())
m = [int(x) for x in input().split()]
m.sort()
print(m[(n-1)//2])