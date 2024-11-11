n = int(input())
raiting = list(map(int, input().split()))
raiting.sort()
if raiting[n] > raiting[n - 1]:
    print('YES')
else:
    print('NO')
