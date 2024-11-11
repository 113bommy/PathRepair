s, v1, v2, t1, t2 = map(int, input().split())

score_1 = s * v1 + 2 * t1
score_2 = s * v2 + 2 * t2

if score_1 == score_2:
    print('Friendship')
elif score_1 < score_2:
    print('First')
else:
    print('Second')
