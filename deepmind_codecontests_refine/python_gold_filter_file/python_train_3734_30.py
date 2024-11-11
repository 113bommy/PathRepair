w = input()
print("Yes" if all([w.count(v) % 2 == 0 for v in set(w)]) else "No")