
n = int(input())
a = list(map(int, input().split()))

if sum(a):
    print('HARD')
else:
    print('EASY')