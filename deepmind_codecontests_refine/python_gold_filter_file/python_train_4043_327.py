A, B, X = map(int, input().split())
print("YNEOS"[not (A<=X<=A+B)::2])