N = input()
 
print("No" if "L" in N[::2] or "R" in N[1::2] else "Yes")