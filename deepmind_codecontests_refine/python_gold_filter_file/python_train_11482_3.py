import sys
from array import array  # noqa: F401
import typing as Tp  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def output(*args):
    sys.stdout.buffer.write(
        ('\n'.join(map(str, args)) + '\n').encode('utf-8')
    )


def main():
    from collections import defaultdict
    t = int(input())
    ans_a = [''] * t

    for ti in range(t):
        n = int(input())
        gang = defaultdict(list)
        cnt = defaultdict(int)

        for i, x in enumerate(map(int, input().split()), start=1):
            gang[x].append(i)
            cnt[x] += 1

        a = sorted((v, k) for k, v in cnt.items())
        if len(a) == 1:
            ans_a[ti] = 'NO'
            continue

        v1 = gang[a[0][1]].pop()
        v2 = gang[a[1][1]][0]
        ans = []
        for _, k in a[1:]:
            for dest in gang[k]:
                ans.append(f'{v1} {dest}')
        for dest in gang[a[0][1]]:
            ans.append(f'{v2} {dest}')

        ans_a[ti] = 'YES\n' + '\n'.join(ans)

    output(*ans_a)


if __name__ == '__main__':
    main()
