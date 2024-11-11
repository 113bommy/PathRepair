n = int(input())
a = list(map(int, input().split()))
sm = sum(a)
odds = 0
for x in a:
    if x % 2:
        odds += 1
if odds == 0:
    print('Second')
elif sm % 2:
    print('First')
else:
    print('First')
