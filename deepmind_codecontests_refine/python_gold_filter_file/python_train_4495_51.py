word = input()
output = ""

for char in word.lower():
	if char not in "aeouiy":
		output += "." + char

print (output)