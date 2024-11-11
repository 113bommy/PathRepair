import sys

MOD = int(1e9+7)
colors_matrix = [
    [2, 4, 3, 5],  # white : green red blue orange
    [2, 4, 3, 5],  # yellow : green red blue orange
    [0, 1, 4, 5],  # green : white yellow red orange
    [0, 1, 4, 5],  # blue : white yellow red orange
    [0, 1, 2, 3],  # red : white yellow green blue
    [0, 1, 2, 3],  # orange : white yellow green blue
]

def rec(tree, vertex, level):
    global dp
    if vertex not in tree:
        return [dp[level]] * 6
    vertex_color_restriction = tree[vertex]
    if level == 0:
        if vertex_color_restriction >= 0:
            res = [0] * 6
            res[vertex_color_restriction] = 1
            return res
        else:
            return [1] * 6
    left = rec(tree, vertex * 2, level - 1)
    right = rec(tree, vertex * 2 + 1, level - 1)
    res = [0] * 6
    for vertex_color in range(6):
        if (vertex_color_restriction >= 0
        and vertex_color_restriction != vertex_color):
            continue
        left_options = 0
        for color_left in colors_matrix[vertex_color]:
            left_options += left[color_left]
        right_options = 0
        for color_right in colors_matrix[vertex_color]:
            right_options += right[color_right]
        res[vertex_color] = (left_options * right_options) % MOD
    return res


def solve():
    global dp
    inp = sys.stdin.readline
    k = int(inp())
    n = int(inp())
    dp = [0] * k
    dp[0] = 1
    for i in range(1, k):
        dp[i] = (dp[i - 1] * 4 * dp[i - 1] * 4) % MOD

    tree = {}
    color_to_id = {
        'white': 0,
        'yellow': 1,
        'green': 2,
        'blue': 3,
        'red': 4,
        'orange': 5,
    }
    for i in range(n):
        v, s = inp().split()
        v = int(v)
        tree[v] = color_to_id[s]
        v //= 2
        while v > 0:
            if v not in tree:
                tree[v] = -1
            v //= 2
    print(sum(rec(tree, 1, k - 1)) % MOD)

def main():
    solve()


if __name__ == '__main__':
    main()
