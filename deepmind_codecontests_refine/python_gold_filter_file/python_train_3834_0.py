import sys
input = sys.stdin.readline

N = int(input())
left = []
right = []
left_inv = []
right_inv = []
for i in range(N):
    L, R = map(int, input().split())
    left.append((R, i))
    right.append((L, i))
    left_inv.append((-L, i))
    right_inv.append((-R, i))

def calc(left, right):
    left.sort(key=lambda p: -p[0])
    right.sort(key=lambda p: p[0])
    used = set()
    x = 0
    ans = 0
    while right or left:
        while right and right[-1][1] in used:
            right.pop()
        if right:
            y, i = right.pop()
            used.add(i)
            if x < y:
                ans += y - x
                x = y
        while left and left[-1][1] in used:
            left.pop()
        if left:
            y, i = left.pop()
            used.add(i)
            if y < x:
                ans += x - y
                x = y
    ans += abs(x)
    return ans

ans = max(calc(left, right), calc(left_inv, right_inv))
print(ans)