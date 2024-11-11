# your code goes here
"""
Write n distinct integers
Make several moves
First move: remove first and second integer.
Second mode: removes the first and second integer from remaining.
And so on.

Bimokh step get's him gcd(x, y) points.

Goal: get Bimokh to get exactly k points.

Action: generate the integers a1, ..., an.

ai is bounded by 10^9.

input is 2 int, n < 1e5 and k < 1e8.

If not possible return -1.

Facts:
Only Bimokh makes the move.
Basically it's the gcd(a1, a2), gcd(a3, a4), ...

gcd is at least 1.
so k >= n/2.

n must be distinct.

We know that gcd(n, n+1) = 1.

So we can put k-(n/2 - 1) in the first pair, and then the rest
"""

n, k = map(int, input().split())
if k == 0 and n == 1:
	print(1)
	exit(0)
if k > 0 and n ==  1:
	print(-1)
	exit(0)
if k < n//2:
	print(-1)
	exit(0)
first_pair = k-(n//2 - 1)
ans = [first_pair, 2*first_pair]
start = 2*first_pair + 1
for i in range(n - 2):
	ans.append(start)
	start += 1
print(*ans)
	