n = int(input())
m = list(map(int, input().split()))
m.sort()
print(m[(n-1)//2])