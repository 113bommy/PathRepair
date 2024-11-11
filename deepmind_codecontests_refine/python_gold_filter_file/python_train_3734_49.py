S = input()
print("Yes" if all([S.count(e) % 2 == 0 for e in set(S)]) else "No")
