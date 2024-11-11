S = input().strip()
print("yes" if len(S) == len(set(list(S))) else "no")
