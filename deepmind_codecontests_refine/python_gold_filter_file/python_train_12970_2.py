def f(n, r, k):
    tmp = n
    for t in range(k):
        for i in range(len(tmp) - 1, -1, -1):
            if int(tmp[i]) % 3 == r:
                tmp = tmp[:i] + tmp[i + 1:]
                break
    for i in range(len(tmp)):
        if int(tmp[i]) != 0:
            return ''.join(tmp[i:])
    if len(tmp) == 0 or 0 < int(tmp[len(tmp) - 1]):
        return ''
    else:
        return '0'


n = list(input())

cnt = {i: 0 for i in range(3)}
for d in n:
    cnt[int(d) % 3] += 1
r = (cnt[1] + 2 * cnt[2]) % 3
if r == 0:
    print(''.join(n))
else:
    ans = []
    if 0 < cnt[r]:
        ans.append(f(n, r, 1))
    if 1 < cnt[3 - r]:
        ans.append(f(n, 3 - r, 2))
    if len(ans) == 0 or len(''.join(ans)) == 0:
        print(-1)
    elif len(ans[-1]) <= len(ans[0]):
        print(ans[0])
    else:
        print(ans[-1])
