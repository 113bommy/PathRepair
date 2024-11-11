s = input()
y = "".join(set(s))
if((len(y) % 2) == 0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")