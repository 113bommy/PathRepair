for _ in range(int(input())):
	r, g, b = map(int, input().split())
	if r+g<b-1 or g+b<r-1 or r+b<g-1:
		print("No")
	else:
		print("Yes")