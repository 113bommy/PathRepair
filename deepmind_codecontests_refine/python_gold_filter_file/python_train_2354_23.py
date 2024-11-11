n = int(input())
r = sum(map(lambda x: int(x)%2, input().split()))
if r > 0:
    print('First')
else:
    print('Second')
