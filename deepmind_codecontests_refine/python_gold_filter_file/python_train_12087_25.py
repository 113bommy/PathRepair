n = int(input())
a = tuple(map(int, input().split()))
for i in range(n):
    if a[i] == 1:
        print('HARD')
        break
else:
    print('EASY')