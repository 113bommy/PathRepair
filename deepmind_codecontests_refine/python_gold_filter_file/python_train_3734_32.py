w = input()
print("Yes" if all(w.count(s)%2 == 0 for s in set(w)) else "No")