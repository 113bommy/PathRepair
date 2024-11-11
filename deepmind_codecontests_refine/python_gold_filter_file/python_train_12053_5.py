from typing import List


class DP:
    N: int
    table: List[List[int]]
    max_all: int
    max_arr: List[int]
    inc: int

    def __init__(self, N: int, x: int, y: int):
        self.N = N
        self.table = [[-(1 << 28)] * (N + 1) for _ in range(N + 1)]
        self.table[x][y] = self.table[y][x] = 0
        self.max_all = 0
        self.max_arr = [-(1 << 28)] * (N + 1)
        self.max_arr[x] = self.max_arr[y] = 0
        self.inc = 0

    def update(self, p: int, q: int, r: int) -> None:
        if p == q == r:
            self.inc += 1
            return

        npqr = self._update_pqr(p, q, r)
        nqrp = self._update_pqr(q, r, p)
        nrpq = self._update_pqr(r, p, q)

        npq = self._update_pq(p, q)
        nqr = self._update_pq(q, r)
        nrp = self._update_pq(r, p)

        np = self._update_p(p)
        nq = self._update_p(q)
        nr = self._update_p(r)

        pq, qr, rp = None, None, None

        if p == q:
            pq = self._update_pair(p, r)

        if q == r:
            qr = self._update_pair(q, p)

        if r == p:
            rp = self._update_pair(r, q)

        self._update_maximum(q, r, npqr)
        self._update_maximum(r, p, nqrp)
        self._update_maximum(p, q, nrpq)

        self._update_maximum(p, q, npq)
        self._update_maximum(q, r, nqr)
        self._update_maximum(r, p, nrp)

        for k in range(self.N + 1):
            self._update_maximum(k, p, np[k])
            self._update_maximum(k, q, nq[k])
            self._update_maximum(k, r, nr[k])

        if pq:
            for k in range(self.N + 1):
                self._update_maximum(k, r, pq[k])

        if qr:
            for k in range(self.N + 1):
                self._update_maximum(k, p, qr[k])

        if rp:
            for k in range(self.N + 1):
                self._update_maximum(k, q, rp[k])


    def _update_maximum(self, x: int, y: int, v: int) -> None:
        self.table[x][y] = self.table[y][x] = max(self.table[x][y], v)
        self.max_all = max(self.max_all, v)
        self.max_arr[x] = max(self.max_arr[x], v)
        self.max_arr[y] = max(self.max_arr[y], v)

    def _update_pair(self, p: int, q: int) -> List[int]:
        return [max(self.table[k][q], self.table[k][p] + 1, self.table[p][k] + 1) for k in range(self.N + 1)]

    def _update_pqr(self, p: int, q: int, r: int) -> int:
        return max(self.table[q][r], self.table[p][p] + 1)

    def _update_pq(self, p: int, q: int) -> int:
        return max(self.table[p][q], self.max_all)

    def _update_p(self, p) -> List[int]:
        return [max(self.table[p][k], self.table[k][p], self.max_arr[k]) for k in range(self.N + 1)]

    def ans(self):
        return self.max_all + self.inc


N = int(input())
A = list(map(int, input().split())) + [0, 0]

dp = DP(N, A[0], A[1])

for i in range(N):
    Z = A[3 * i + 2: 3 * i + 5]
    dp.update(Z[0], Z[1], Z[2])
    # print("out", dp.table, dp.max_all, dp.max_arr)

print(dp.ans())
