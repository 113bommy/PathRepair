n = int(input())
for i in range(n):
    n, n, m = map(int, input().split())
    print('YES' if max(map(int, input().split())) >= max(map(int, input().split())) else 'NO')
