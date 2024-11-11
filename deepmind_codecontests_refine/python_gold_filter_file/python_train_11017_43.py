N = int(input())
a = list(map(int, input().split()))

amin = min(a)
amax = max(a)
if abs(amin) < abs(amax):
    index = a.index(amax)
    a = list(map(lambda x: x + amax, a))
else:
    index = a.index(amin)
    a = list(map(lambda x: x + amin, a))

ans = [(index+1, i+1) for i in range(N)]
if a[0] > 0:
    ans += [(i+1, i+2) for i in range(N-1)]
else:
    ans += [(i+1, i) for i in range(N-1, 0, -1)]
print(len(ans))
print('\n'.join(map(lambda xy: '%d %d' % xy, ans)))
