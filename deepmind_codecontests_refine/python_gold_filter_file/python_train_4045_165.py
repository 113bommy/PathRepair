s = list(input())
print("yes" if len(s) == len(list(set(s))) else "no")
