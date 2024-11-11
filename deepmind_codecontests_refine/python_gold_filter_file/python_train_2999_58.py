S = input()
print("Yes" if sum([2==S.count(ch) for ch in S])==4 else "No")
