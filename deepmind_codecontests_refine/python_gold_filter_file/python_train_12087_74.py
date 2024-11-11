n = int(input())
m = list(map(int,input().split()))

if sum(m) > 0:
    print('HARD')
else:
    print('EASY')