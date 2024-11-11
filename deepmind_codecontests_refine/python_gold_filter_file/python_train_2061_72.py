S = input()

if set(S[::2]) <= set("RUD") and set(S[1::2]) <= set("LUD"):
    print("Yes")
else:
    print("No")
