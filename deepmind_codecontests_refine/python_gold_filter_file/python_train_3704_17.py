def main():
	s = input().strip()
	max_val = -1
	for c in s:
		n = ord(c) - ord('a')
		if n == max_val + 1:
			max_val += 1
		elif n > max_val:
			print("NO")
			return

	print("YES")

main()