
a = int(input())
b = sorted(list(map(int,input().split())))
print('YES' if b[a - 1] < b[a] else 'NO')