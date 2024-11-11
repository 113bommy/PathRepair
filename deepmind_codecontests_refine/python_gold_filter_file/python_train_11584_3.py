import threading
import sys
data = sys.stdin.read()
*nums, = map(int, data.split())
idx = -1
def inp():
    global idx
    idx += 1
    if idx < len(nums):
        return nums[idx]
    return -1

def dfs(g, p, h, n, v, par):
    total = p[v]
    total_happy = 0
    total_sad = 0
    for ch in g[v]:
        if ch != par:
            is_ok, ch_happy, ch_sad, ch_total = dfs(g, p, h, n, ch, v)
            total_happy += ch_happy
            total_sad += ch_sad
            total += ch_total
            if not is_ok:
                return False, -1, -1, -1

    happy = (total + h[v]) // 2
    if happy * 2 != (total + h[v]):
        return False, -1, -1, -1

    sad = total - happy

    if len(g[v]) == 1 and g[v][0] == par or n == 1:
        # print("leaf ", v + 1, (happy, sad, total))
        if happy * 2 != p[v] + h[v] or happy < 0 or sad < 0:
            # print("broken")
            return False, -1, -1, -1
        return True, happy, sad, total
    if happy < 0 or sad < 0:
        # print("broken at", v + 1, (happy, sad, total))
        return False, -1, -1, -1
    # print("state at ", v + 1, (total, total_sad, total_happy, sad, happy))
    if sad > total_sad + p[v]:
        # print("sad imabalance at", v + 1)
        return False, -1, -1, -1

    return True, happy, sad, total


def solve(g, p, h, n):
    return dfs(g, p, h, n, 0, -1)[0]


sys.setrecursionlimit(100010)

ans = []
def main():
    global ans
    for _ in range(inp()):
        n, _ = inp(), inp()
        *p, = [inp() for _ in range(n)]
        *h, = [inp() for _ in range(n)]
        g = [[] for _ in range(n)]
        for _ in range(n - 1):
            src, dst = inp(), inp()
            src -= 1
            dst -= 1
            g[src].append(dst)
            g[dst].append(src)
        try:
            ans.append("YES" if solve(g, p, h, n) else "NO")
        except Exception as exc:
            print(exc)

try:
    # threading.stack_size(2 ** 23)
    t = threading.Thread(target=main)
    t.start()
    t.join()
except Exception as exc:
    print(repr(exc))


print("\n".join(ans))
