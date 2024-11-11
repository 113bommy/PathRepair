import math
from collections import defaultdict


def main():
    p = 31
    m = 1e9 + 9
    def string_hash(s):
        hash_value = 0
        p_pow = 1
        for c in s:
            hash_value = (hash_value + (ord(c)-ord('a')+1) * p_pow) % m
            p_pow = (p_pow * p) % m
        return hash_value

    n = int(input())
    words = input().split()
    eq = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i == j:
                eq[i][j] = eq[j][i] = True
            else:
                eq[i][j] = eq[i][j] = words[i] == words[j]

    dp = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n-1, -1, -1):
        for j in range(n-1, -1, -1):
            if not eq[i][j]:
                dp[i][j] = 0
            else:
                if i < n-1 and j < n-1:
                    dp[i][j] = dp[i+1][j+1] + 1
                else:
                    dp[i][j] = 1

    all = sum(len(w) for w in words) + n-1
    ans = all
    for start in range(n):
        size = 1
        while start + size < n:
            num = 1
            pos = start + size
            while pos + size <= n:
                if dp[start][pos] >= size:
                    num += 1
                    pos += size
                else:
                    pos += 1
            if num > 1:
                segsize = sum(len(words[i]) for i in range(start, start+size)) + size-1
                newsize = size
                ans = min(ans, all - num * segsize + num * newsize)
            size += 1

    print(ans)


if __name__ == '__main__':
    main()
