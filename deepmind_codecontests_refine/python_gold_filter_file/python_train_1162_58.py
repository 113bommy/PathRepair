current_HP = input()
current_HP_mod4 = int(current_HP) % 4

if current_HP_mod4 == 0:
	print("1 A")
elif current_HP_mod4 == 1:
	print("0 A")
elif current_HP_mod4 == 2:
	print("1 B")
else:
	print("2 A")