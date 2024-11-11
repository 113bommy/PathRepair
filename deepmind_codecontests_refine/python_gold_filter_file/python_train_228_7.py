for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    _p = list(map(int, input().split()))
    a = ""
    let = [0] * 26
    p = [i - 1 for i in _p]
    pref = [0] * len(s)
    for i in range(len(p)):
        pref[p[i]] += 1
    for i in range(len(s) - 1, 0, -1):
        pref[i - 1] += pref[i]
    for i in range(len(s)):
        let[ord(s[i]) - ord('a')] += pref[i]
        let[ord(s[i]) - ord('a')] += 1
    print(*let)