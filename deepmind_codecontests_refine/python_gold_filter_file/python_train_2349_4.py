import sys
a, b = map(int, input().split())
anscnt = 1
ans = []
ans.append(b)
while b != a:
    if b < a:
        print('NO')
        exit(0)
    elif b % 10 == 1:
        b = (b-1)//10
    elif b % 2 == 0:
        b //= 2
    else:
        print('NO')
        exit(0)
    anscnt += 1
    ans.append(b)
print('YES')
print(anscnt)
print(*ans[::-1])
