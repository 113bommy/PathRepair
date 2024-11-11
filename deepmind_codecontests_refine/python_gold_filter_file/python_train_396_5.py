s = input()
n = len(s)
bits = dict()
bits[0] = 0
bit = 0
for i in range(n):
	x = ord(s[i])-97
	bit ^= (1<<x)
	for j in range(26):
		new_bit = bit ^ (1<<j)
		if new_bit in bits:
			#print(bin(bit)[2:], bin(new_bit)[2:])
			if bit in bits:
				bits[bit] = min(bits[bit], bits[new_bit] + 1)
			else:
				bits[bit] = bits[new_bit] + 1
			#print(bits[bit])
		#print("-----")
if bit not in bits:
	print(-1)
else:
	print(max(1, bits[bit]))