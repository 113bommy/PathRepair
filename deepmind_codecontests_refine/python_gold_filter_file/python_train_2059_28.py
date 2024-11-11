a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())
print("YES" if (v - w) * t >= abs(b - a) else "NO")