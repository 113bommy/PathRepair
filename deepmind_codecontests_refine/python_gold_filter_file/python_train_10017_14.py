n = int(input())
l = list(map(int, input().split()))
odds = 0
for i in l:
    if i % 2 == 1:
        odds += 1

if odds % 2 == 0:
    print(n - odds)
else:
    print(odds)