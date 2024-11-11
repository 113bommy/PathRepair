n = int(input())
x = [int(e) for e in input().split(' ')]
y = [int(e) for e in input().split(' ')]

if len(set(x[1:]+y[1:])) == n:
    print('I become the guy.')
else:
    print('Oh, my keyboard!')