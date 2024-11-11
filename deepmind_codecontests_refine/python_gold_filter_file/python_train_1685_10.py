T = int(input())
for i in range(0, T):
	n = int(input())
	inp = input()
	inp_array = inp.split(" ")
	inp_array_int = []
	for i in inp_array:
		inp_array_int.append(int(i))
	set_re = {inp_array_int[-1]}
	inp_array_int.reverse()
	count =0
	minimum = inp_array_int[0]
	for i in inp_array_int[1:]:
		if i > minimum:
			count += 1
		else:
			minimum = i	
		#set_re.add(i)
	print(count)		
		