N = int(input())
S = list(map(int, input().split()))
S.sort()
print(S[N//2]-S[N//2-1])