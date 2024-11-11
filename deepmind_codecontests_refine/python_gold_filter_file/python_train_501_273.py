input()
S=list(map(int,input().split()))
S.sort()
print(S[-1]-S[0])