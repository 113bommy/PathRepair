import sys
import io

stream_enable = 0

inpstream = """
9
(()
((())
(
)
(()()(()())))
)
)(()(
)())(
)()(
"""

if stream_enable:
    sys.stdin = io.StringIO(inpstream)
    input()

def inpmap():
    return list(map(int, input().split()))

n = int(input())
arr = []
for i in range(n):
    x = input()
    a = 0
    s = False
    for y in x:
        if y == '(':
            a += 1
        else:
            a -= 1
        if a < 0:
            s = True
    if s and a >= 0:
        continue
    a = 0
    s = False
    for y in x[::-1]:
        if y == '(':
            a += 1
        else:
            a -= 1
        if a > 0:
            s = True
    if s and a <= 0:
        continue
    arr.append(a)

    # arr.append(x.count('(') - x.count(')'))
s = 0
# print(arr)
# for x in set(arr):
st = set(arr)
for x in st:
    if x > 0:
        continue
    elif x == 0:
        s += arr.count(x) ** 2
    else:
        s += arr.count(x) * arr.count(-x)
print(s)
