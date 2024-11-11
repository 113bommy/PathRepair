n = input()

vowel = "aeiouyYAEIOU"

for i in n:
	if i not in vowel:
		print(".",end='')
		print(i.lower(),end='')
