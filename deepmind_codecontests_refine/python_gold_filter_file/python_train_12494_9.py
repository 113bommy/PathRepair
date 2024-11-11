# -*- coding: utf-8 -*-

count = 0
backslash_index = []
area_pond = []
pending_area=[]
for index,symbol in enumerate(input()):
	if symbol == "\\":
		backslash_index += [index]
	elif symbol == '/' and backslash_index:
		last_bs_index = backslash_index.pop()
		diff = index - last_bs_index 
		count += diff 
		while area_pond and area_pond[-1] > last_bs_index:
			diff += pending_area.pop()
			area_pond.pop()

		area_pond += [last_bs_index]
		pending_area += [diff]

print(count)
print(len(area_pond),*(pending_area))

