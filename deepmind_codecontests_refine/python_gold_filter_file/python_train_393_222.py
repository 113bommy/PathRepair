s = input()
r = s.count("0")
print(min(r, len(s) - r) * 2)
