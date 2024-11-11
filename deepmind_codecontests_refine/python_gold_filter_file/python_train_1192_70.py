d = input()
s = input()
k = "qwertyuiopasdfghjkl;zxcvbnm,./"
shift = -1 if d == "R" else 1
print("".join(k[(k.index(c) + shift) % len(k)] for c in s))
