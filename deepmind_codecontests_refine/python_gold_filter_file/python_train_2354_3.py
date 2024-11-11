def check():
	for _ in input().split():
		if int(_)&1:return True
	return False

n = int(input())
if check():print("First")
else:print("Second")