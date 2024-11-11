# Accepted: ??


inp_str = input()

if len(inp_str) == 1:
    if inp_str.isupper():
        print(inp_str.lower())
    else:
        print(inp_str.upper())
elif inp_str.isupper():
    print(inp_str.lower())
elif inp_str[0].isupper():
    print(inp_str)
elif inp_str[1:].isupper():
    print(inp_str[0].upper() + inp_str[1:].lower())
else:
    print(inp_str)
