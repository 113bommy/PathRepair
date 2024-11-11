a = input(); b = input(); print("".join(map("".join, zip(a, b))) + (a[-1] if len(a) is not len(b) else ""))
