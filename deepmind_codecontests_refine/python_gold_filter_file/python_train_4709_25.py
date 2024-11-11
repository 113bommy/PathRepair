inp_str = input()
l = len(inp_str)

if inp_str.islower() and l == 1:
	print(inp_str.upper())
elif inp_str.islower():
	print(inp_str)
elif inp_str.isupper():
	print(inp_str.lower())
elif inp_str[0].islower and inp_str[1:].isupper():
	print(inp_str[0].upper() + inp_str[1:].lower())
else:
	print(inp_str)