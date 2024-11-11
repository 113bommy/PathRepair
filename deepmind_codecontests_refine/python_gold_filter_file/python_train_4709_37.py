inp=input()
x=inp[0].lower()+inp[1:].upper()
if inp==inp.upper():
    print(inp.lower())
elif inp==x:
    print(inp.title())
else:
    print(inp)
