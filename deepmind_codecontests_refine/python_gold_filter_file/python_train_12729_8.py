first = input()
second = input()
total = input()
need = first + second
if len(need) != len(total):
	print("NO")
else:
	for letters in need:
		if need.count(letters) != total.count(letters): 
			print("NO")
			exit()
	print("YES")