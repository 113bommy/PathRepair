# https://codeforces.com/problemset/problem/1608/B

def answer(n:int, up:int, down:int) -> str:
    if up+down > n-2 or abs(up-down) > 1: return '-1'
    common = min(up, down)
    answer = []
    l = 1; r = n
    if up == down == 0:
        answer = range(1, n+1)
    elif up > down:
        for i in range(common+1):
            answer.append(l)
            answer.append(r)
            l += 1
            r -= 1
        answer += list(range(r, l-1, -1))
    elif up == down:
        for i in range(common):
            answer.append(l)
            answer.append(r)
            l += 1
            r -= 1
        answer += list(range(l, r+1))
    else:
        for i in range(common+1):
            answer.append(r)
            answer.append(l)
            l += 1
            r -= 1
        answer += list(range(l, r+1))

    return ' '.join(map(str, answer))

for _ in range(int(input())):
    n, a, b = map(int, input().split())
    print(answer(n, a, b))
