import sys
input = sys.stdin.readline

base = 27
mod = (1 << 61) - 1

N = int(input())
S = [input().rstrip()[::-1] for _ in range(N)]
S.sort(key=lambda s: -len(s))
cnt = {}
ans = 0
one = [0] * 26
for s in S:
    n = len(s)
    if n == 1:
        ans += one[ord(s[0]) - ord('a')]
        continue
    hashes = [0] * (n - 1)
    hashes[0] = ord(s[0]) - ord('a') + 1
    for i in range(1, n - 1):
        hashes[i] = (hashes[i-1] * base + ord(s[i]) - ord('a') + 1) % mod
    if hashes[-1] in cnt:
        ans += cnt[hashes[-1]][ord(s[-1]) - ord('a')]
    found = [0] * 26
    found[ord(s[-1]) - ord('a')] = 1
    for i in range(n - 2, 0, -1):
        found[ord(s[i]) - ord('a')] = 1
        if hashes[i-1] not in cnt:
            cnt[hashes[i-1]] = [0] * 26
        for c in range(26):
            cnt[hashes[i-1]][c] += found[c]
    found[ord(s[0]) - ord('a')] = 1
    for c in range(26):
        one[c] += found[c]
print(ans)
