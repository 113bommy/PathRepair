inp = input()


if not inp.count("o"):
    print("YES")
    exit(0)
if(inp.count("-") % inp.count("o") == 0):
    print("YES")
else:
    print("NO")
