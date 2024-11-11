w = input()

print("Yes" if all([w.count(c)%2==0 for c in set(w)]) else "No")