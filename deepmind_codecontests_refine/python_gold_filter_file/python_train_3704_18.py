mx = int(96)
for ch in input():
	if ord(ch) > mx+1:
		print("NO")
		break
	mx = max(ord(ch), mx)
else:
	print("YES")