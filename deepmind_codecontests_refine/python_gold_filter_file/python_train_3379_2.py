n = int(input())
P = set(int(x) for x in input().split()[1:])
Q = set(int(x) for x in input().split()[1:])
if P|Q == set(range(1,n+1)):
    print('I become the guy.')
else:
    print('Oh, my keyboard!')
