t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    a, b = map(int, input().split())
    ans1 = min(x, y) * b
    ans1 += (max(x, y) - (ans1//b)) * a
    ans2 = x*a + y*a
    print(min(ans1, ans2))