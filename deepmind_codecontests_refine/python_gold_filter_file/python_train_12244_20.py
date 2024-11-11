n, k = map(int, input().split())
s = input()
for i in range(ord('a'), ord('z') + 1):
    if s.count(chr(i)) > k:
        print('NO')
        break
else:
    print('YES')