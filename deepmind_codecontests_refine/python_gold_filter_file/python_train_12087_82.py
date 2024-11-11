a1 = int(input())
a = list(map(int, input().split()))
if sum(a) > 0:
    print('HARD')
else:
    print('EASY')