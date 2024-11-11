n = int(input())

for i in range(n):
    s = list(map(int, input().split()))
    s.sort()
    if(s[2] ** 2 == s[1] ** 2 + s[0] ** 2):
        print('YES')
    else:
        print('NO')
