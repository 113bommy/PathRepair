from functools import cmp_to_key


def calc_lcp(s, sa):
    rank = [0 for _ in range(len(s))]
    for i in range(len(s)):
        rank[sa[i]] = i
    lcp = [0 for _ in range(len(s) - 1)]
    h = 0
    for i in range(len(s)):
        if rank[i] < len(s) - 1:
            while max(i, sa[rank[i] + 1]) + h < len(s) and s[i + h] == s[sa[rank[i] + 1] + h]:
                h += 1
            lcp[rank[i]] = h
            if h > 0:
                h -= 1
    return lcp, rank

def suffix_array(s):
        rank = [ord(d) for d in s]

        k = 1
        while k < len(s):
            suffixes = [((rank[i], rank[i + k] if i + k < len(s) else -1), i) for i in range(len(s))]
            suffixes.sort()

            cnt = 0
            rank[suffixes[0][1]] = 0
            for i in range(1, len(s)):
                if suffixes[i][0] != suffixes[i - 1][0]:
                    cnt += 1
                rank[suffixes[i][1]] = cnt

            if cnt == len(s) - 1:
                break
            k *= 2

        sa = [0 for _ in s]
        for i in range(len(s)):
            sa[rank[i]] = i
        # print(sa)
        return sa

def kmp(s, p):
    pi = [0 for _ in range(len(p))]
    k = 0
    for i in range(1, len(p)):
        while k > 0 and p[k] != p[i]:
            k = pi[k - 1]
        if p[k] == p[i]:
            k += 1
        pi[i] = k

    k = 0
    resp = []
    for i in range(len(s)):
        while k > 0 and p[k] != s[i]:
            k = pi[k - 1]
        if p[k] == s[i]:
            k += 1
        if k == len(p):
            resp.append(i - len(p) + 1)
            k = pi[k - 1]
    return resp

def lower_bound(list, value):
    left = 0
    right = len(list)
    while left < right:
        mid = int((left + right) / 2)
        if list[mid] < value:
            left = mid + 1
        else:
            right = mid
    return left


s = input()
start = input()
end = input()

indStart = kmp(s, start)
indEnd = kmp(s, end)

if len(indStart) == 0 or len(indEnd) == 0:
    print(0)

else:
    sa = suffix_array(s)
    lcp, rank = calc_lcp(s, sa)

    ind = rank[indStart[0]]
    for st in indStart:
        ind = min(ind, rank[st])

    resp = len(indEnd) - lower_bound(indEnd, sa[ind] + max(0, len(start) - len(end)))
    while ind < len(lcp) and lcp[ind] >= len(start):
        ind += 1
        resp += len(indEnd) - lower_bound(indEnd, sa[ind] + max(0, max(lcp[ind - 1] + 1, len(start)) - len(end)))

    print(resp)

