#!/usr/bin/env python3

original = (input().strip())
descending = "".join(sorted(input().strip(), reverse=True))
# print(original)
# print(descending)
newString = ""
index = 0
did_not_finish_index = len(original)
for x in range(len(original)):
	if index >= len(descending): 
		did_not_finish_index = x
		break
	if original[x] < descending[index]:
		newString += descending[index]
		index += 1
	else:
		newString += original[x]

for y in range(did_not_finish_index, len(original)):
	newString += original[y]
print(newString)