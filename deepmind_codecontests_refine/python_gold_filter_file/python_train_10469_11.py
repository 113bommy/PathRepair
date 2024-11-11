import string

counter = 0
input = input()
letters = string.ascii_lowercase
numberOfLetters = len(letters)
point = letters[0]

for char in input:
	indexOfPoint = letters.index(point) + 1
	indexOfTarget = letters.index(char) + 1
	clockwise = abs(indexOfPoint - indexOfTarget)
	counterclockwise = numberOfLetters - clockwise
	step = min(clockwise, counterclockwise)
	counter += step
	point = char
print(counter)