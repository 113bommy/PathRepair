A, V = map(int, input().split())
B, W = map(int, input().split())
T = int(input())

if abs(A-B) <= T*(V-W):
    print("YES")
else:
    print("NO")
