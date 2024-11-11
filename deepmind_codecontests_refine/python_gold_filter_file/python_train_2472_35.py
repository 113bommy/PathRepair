n = int(input())
a = list(map(int, input().split()))
print(sorted(a)[(n-1)//2])
