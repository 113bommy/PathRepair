n = int(input())
GOLOSOVANIE = list(map(int, input().split()))
cnt = int(0)
for i in range(n):
    if GOLOSOVANIE[i] == 1:
        cnt += 1
if cnt >= 1:
    print('HARD')
else:
    print('EASY')
