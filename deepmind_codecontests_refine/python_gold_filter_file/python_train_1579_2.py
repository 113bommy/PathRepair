input()
a = list(map(int, input().split()))
if a.count(1) == 0:
	print(' '.join(map(str, a)))
elif a.count(2) == 0:
	print(' '.join(map(str, a)))
else:
	print(f"2 1 {'2 ' * (a.count(2)-1)}{'1 ' * (a.count(1)-1)}")
