S = input()
print("Yes" if all(S.count(s)%2 == 0 for s in set(S)) else "No")