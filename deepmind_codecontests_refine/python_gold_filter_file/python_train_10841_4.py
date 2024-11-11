"""
## Name of Prob
A. Ilya and a Colorful Walk

## Link
https://codeforces.com/contest/1119/problem/A

## Note
n houses with distance 1 for each
n colors c_i
find maximum distance i to j which c_i != c_j

## Input
n; num of houses
c_i; color of houses

## Output
maximum distance

## Strategy
read color of houses
save color and first pos of each color

1 2 3 2 3 => t = [[1, 0], [2, 1], [3, 2], [2, 3], [3, 4]]

len(t) > 1 cus there must be exist two different color

if t[0][0] == t[-1][0]:
    first and last color is different => answer will be (n - 1)
else:
    compare (second to last(n-1)), (first to before last(n-2)))
"""
n = int(input())
h = list(map(int, input().split()))

# current_pos = [h[0], 0]
# current_color, current_pos = h[0], 0
t = [[h[0], 0]]
for i, color in enumerate(h):
    if color != t[-1][0]:
        t.append([color, i])

# print(t)
if t[0][0] != t[-1][0]:
    print(n - 1)
else:
    print(max(n - 1 - t[1][1], t[-2][1]))
