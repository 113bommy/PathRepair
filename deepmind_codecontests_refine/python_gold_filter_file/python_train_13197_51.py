n = int(input())
a = list(map(int, input().split()))*2
a.sort()
print(sum(a[n:-1]))