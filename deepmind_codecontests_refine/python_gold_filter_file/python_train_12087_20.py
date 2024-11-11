n = int(input())
a = [int(i) for i in input().split()]
if a.count(1)>0:
    print('HARD')
else:
    print('EASY')