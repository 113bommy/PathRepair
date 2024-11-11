A, B = [s == "H" for s in input().split()]

print(["H", "D"][A ^ B])