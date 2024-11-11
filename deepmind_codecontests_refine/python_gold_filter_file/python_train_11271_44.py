def solution(n, s):
    ans = []
    a = 0
    for i in range(n):
        ans.append(s[i + a])
        a += 1
    return "".join(ans)

t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    print(solution(n, s))

    