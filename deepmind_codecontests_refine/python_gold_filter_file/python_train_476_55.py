s, v1, v2, t1, t2 = list(map(int, input().split()))
if s * v1 + 2 * t1 > s * v2 + 2 * t2:
    print('Second')
elif s * v1 + 2 * t1 < s * v2 + 2 * t2:
    print('First')
else:
    print('Friendship')
