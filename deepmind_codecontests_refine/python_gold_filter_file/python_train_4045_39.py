S = list(input())
print("yes" if len(S) == len(list(set(S))) else "no")