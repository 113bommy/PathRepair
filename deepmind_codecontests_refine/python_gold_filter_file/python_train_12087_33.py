n = int(input())
a = list(map(int, input().split()))
for i in range(0, n):
    if a[i] == 1:
        print('HARD')
        break
else:
    print('EASY')