import sys
import re
n = int(input())
a = 0
b = 0
a_b = 0
cnt = 0
for i in range(n):
    s = sys.stdin.readline().strip()
    cnt += len(re.findall("AB", s))
    a += s[0] == "B"
    b += s[-1] == "A"
    a_b += (s[0] == "B" and s[-1] == "A")
plus = 0
if a == b == a_b != 0:
    plus -= 1
plus += min(a, b)
print(cnt + plus)