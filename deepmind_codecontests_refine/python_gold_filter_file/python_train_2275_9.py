_ = input()
a = list(filter(lambda x: int(x) % 2 == 1, input().split()))
print('YES' if len(a) % 2 == 0 else 'NO')