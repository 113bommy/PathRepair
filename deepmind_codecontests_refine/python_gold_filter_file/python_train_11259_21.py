"""
## Name of Prob
A. Serval and Bus

## Link
https://codeforces.com/contest/1153/problem/A

## Note

## Input

## Output

## Strategy
"""

_DEBUG = True
n, t = map(int, input().split())

min_wait_time = float('inf')
min_wait_time_idx = None

for i in range(n):
    s, d = map(int, input().split())
    wait_time = None
    if t <= s:
        wait_time = s - t
    else:
        wait_time = (d - ((t - s) % d)) % d

    if wait_time < min_wait_time:
        min_wait_time = wait_time
        min_wait_time_idx = i

print(min_wait_time_idx + 1)
