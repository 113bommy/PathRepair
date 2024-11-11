def solve(s: str, t: str):
    import collections, bisect
    
    d = collections.defaultdict(list)
    for i, ch in enumerate(s):
        d[ch].append(i)

    ptr = [-1] * len(t)
    for i, ch in enumerate(t):
        if not ch in d:
            return -1

        if i == 0:
            ptr[i] = d[ch][0]
        else:
            x = bisect.bisect_left(d[ch], ptr[i-1]+1)
            if x == len(d[ch]):
                ptr[i] = d[ch][0]
            else:
                ptr[i] = d[ch][x]

    ans = 1
    for i in range(len(ptr)-1):
        if ptr[i] >= ptr[i+1]:
            ans += 1

    return ans


T = int(input())
for _ in range(T):
    s = input()
    t = input()
    print(solve(s, t))