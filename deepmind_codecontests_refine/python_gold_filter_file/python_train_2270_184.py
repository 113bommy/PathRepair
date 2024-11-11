A, B = map(int, input().split())
S = input()
print(S[:B-1] + S[B-1].lower() + S[B:])