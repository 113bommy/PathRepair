A, B, C, D = map(int, input().split())
if -(-C // B) <= -(-A // D):
    print('Yes')
else:
    print('No')