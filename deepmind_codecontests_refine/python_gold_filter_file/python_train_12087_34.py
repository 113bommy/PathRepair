a = int(input())
b = [int(i) for i in input().split()]
if b.count(1) > 0:
    print('HARD')
else:
    print('EASY')