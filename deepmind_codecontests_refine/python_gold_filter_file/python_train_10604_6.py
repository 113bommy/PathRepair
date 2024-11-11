A = "CODEFESTIVAL2016"
S = input()
print(sum(0 if s == a else 1 for s, a in zip(A, S)))
