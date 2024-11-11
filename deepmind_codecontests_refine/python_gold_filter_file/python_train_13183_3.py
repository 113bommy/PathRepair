
def make_number(b,chars):
	if len(chars) == 0:
		return ""
	target = chars[0]
	for i in chars:
		if int(b[0]) <= int(i):
			break
		target = i
	chars.remove(target)
	return target + "".join(chars[::-1])


def find_number(b,chars):
	backup_chars = list(chars)
	if len(b) == 1:
		return chars[0]
	elif b[0] in chars:
		chars.remove(b[0])
		num = b[0] + find_number(b[1:],chars)
		if min(num,b) == b and b != num:
			return make_number(b,backup_chars)
		else:
			return num

	else:
		return make_number(b,backup_chars)

a,b = str(input()), str(input())
chars = [i for i in a]
chars.sort()

if len(a) < len(b):
	print("".join(chars[::-1]))
else:
	print(find_number(b,chars))