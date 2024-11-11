n = input()
l = n.replace("hi","")

print("No" if len(set(l)) != 0 else "Yes")