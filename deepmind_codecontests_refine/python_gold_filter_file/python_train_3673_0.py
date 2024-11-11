import sys

tests = int(sys.stdin.readline())
for i in range(tests):
	rooms = int(sys.stdin.readline())
	belts = sys.stdin.readline().strip()
	# Test for cull circle
	if "<" not in belts:
		print(rooms)
		continue
	if ">" not in belts:
		print(rooms)
		continue
	if "<" not in belts and ">" not in belts:
		print(rooms)
		continue
	ret_rooms = 0
	for room in range(rooms):
		if belts[(room) % rooms] == ">" and belts[(room + 1) % rooms] == "<":
				pass # trapped
		elif (belts[(room) % rooms] == "-") or (belts[(room + 1) % rooms] == "-"):
				ret_rooms += 1
		
	print(ret_rooms)
				
