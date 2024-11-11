n = int(input())
f = lambda x: 0 if x % 2 > 0 else 1 + f(x // 2)
print(sum(f(int(x)) for x in input().split()))