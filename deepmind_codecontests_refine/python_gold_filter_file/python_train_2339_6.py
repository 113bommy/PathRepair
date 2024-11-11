arr = ([input()[0], input()[0], input()[0]])

st = sorted(arr)
names = ["F", "M", "S"]

if st == ["p", "r", "r"]:
    print(names[arr.index("p")])
elif st == ["r", "s", "s"]:
    print(names[arr.index("r")])
elif st == ["p", "p", "s"]:
    print(names[arr.index("s")])
else:
    print("?")




