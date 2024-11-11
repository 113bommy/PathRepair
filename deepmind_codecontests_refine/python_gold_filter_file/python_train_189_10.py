import sys
from operator import itemgetter

mod = 10**9 + 7
inf = 1<<30

def solve():
    N, M = map(int, sys.stdin.readline().split())
    sects = []

    for i in range(N):
        li, ri = map(int, sys.stdin.readline().split())

        sects.append((li - 1, ri, ri - li + 1))

    sects.sort(key=itemgetter(2))

    # print(sects)

    print(N)

    left = 0

    ft = FenwickTree([0]*(M + 1))

    for d in range(2, M + 1):
        for j in range(left, N):
            if sects[j][2] >= d:
                left = j
                break
            else:
                ft.add(sects[j][0], 1)
                ft.add(sects[j][1], -1)
        else:
            left = N

        # print('left', left)
        # print(ft.data)

        ans = N - left + sum(ft.get_sum(j) for j in range(d, M + 1, d))
        
        print(ans)

class FenwickTree:
    def __init__(self, a):
        self.n = len(a)
        self.data = [0] + a[:]

        for i in range(1, self.n + 1):
            if i + (i & (-i)) <= self.n:
                self.data[i + (i & (-i))] += self.data[i]

    def add(self, i, x):
        ''' a[i] += x '''
        i += 1 # 0-oringn -> 1-origin

        while i <= self.n:
            self.data[i] += x
            i += i & (-i)

    def get_sum(self, r):
        ''' sum[a_0 .. a_r) '''
        res = 0

        while r > 0:
            res += self.data[r]
            r -= r & (-r)

        return res


if __name__ == '__main__':
    solve()