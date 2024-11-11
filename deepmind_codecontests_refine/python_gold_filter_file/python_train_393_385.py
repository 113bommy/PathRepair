S = input()
n = S.count("0")
print(min(n, len(S) - n) * 2)
