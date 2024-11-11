S = input()
print("No" if "L" in S[0::2] or "R" in S[1::2] else "Yes")