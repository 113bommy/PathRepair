#!/usr/bin/env python3

read_ints = lambda : list(map(int, input().split()))

def solve(n, m, s):
    ans = []
    i = 1
    while m -i >= 0:
        if i not in s:
            m -= i
            ans.append(i)
        i+=1
    return ans

if __name__ == '__main__':
    n, m = read_ints()

    s = set(read_ints())
    ans = solve(n, m, s)
    print(len(ans))
    for a in ans:
        print(a, end=" ")