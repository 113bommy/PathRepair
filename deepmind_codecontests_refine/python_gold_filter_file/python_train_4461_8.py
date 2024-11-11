A, B, C = map(int, input().split())
print(C if A == B else B if A == C else A)