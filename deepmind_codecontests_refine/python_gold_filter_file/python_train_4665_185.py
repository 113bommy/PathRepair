N = int(input())
Q = list(map(int, input().split()))
Q.sort()
print(Q[N//2] - Q[N//2-1])