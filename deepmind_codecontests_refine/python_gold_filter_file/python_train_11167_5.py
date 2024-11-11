from sys import stdin

class Problem:
    def __init__(self, n, k, s):
        self.n = n
        self.k = k
        self.a = list(s)

    def solve(self):
        le = 0
        ri = 0
        count = { '0': 0, '1': 0, '?': 0 }

        while ri < k:
            count[ self.a[ri] ] += 1

            ri += 1
        
        while le <= n - k:
            if count['0'] * 2 > k:
                return 'NO'
            if count['1'] * 2 > k:
                return 'NO'

            if ri < n and self.a[le] != self.a[ri]:
                count[ self.a[le] ] -= 1
                if self.a[ri] == '?':
                    self.a[ri] = self.a[le]
                elif self.a[le] != '?':
                    return 'NO'

                count[ self.a[ri] ] += 1

            ri += 1
            le += 1

        return 'YES'

cases = int(stdin.readline())
for test in range(cases):
    n, k = list(map(int, stdin.readline().split()))
    a = stdin.readline().strip()
    ans = Problem(n, k, a).solve()
    print(ans)
