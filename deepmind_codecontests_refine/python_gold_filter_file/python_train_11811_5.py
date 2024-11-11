n = int(input())
s = n * (n + 1) / 2
a = list(map(int, input().split()))
print(int(s - sum(a)))