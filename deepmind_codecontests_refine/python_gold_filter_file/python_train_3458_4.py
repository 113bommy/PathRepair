import atexit
import io
import sys

input = sys.stdin.readline
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


n, m = map(int, input().split())
a = [[int(x) for x in input().split()] for _ in range(n)]
res = 0
for j in range(m):
    cnt = [0] * n
    for i in range(n):
        if (a[i][j] - 1) % m == j and ((a[i][j] - j - 1) // m) < n:
            p = (a[i][j] - 1) // m
            cnt[i - p if i >= p else i + n - p] += 1
    for i in range(n):
        cnt[i] = n - cnt[i] + i
    res += min(cnt)
print(res)