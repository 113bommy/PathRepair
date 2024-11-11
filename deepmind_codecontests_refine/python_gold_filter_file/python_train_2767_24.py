num_turns = int(input())
end_pos = int(input())
zero_first_pos = [0, 1, 1, 2, 2, 0]
one_first_pos = [1, 0, 2, 1, 0, 2]
two_first_pos = [2, 2, 0, 0, 1, 1]
if(end_pos == 0):
	print(zero_first_pos[num_turns % 6])
elif(end_pos == 1):
	print(one_first_pos[num_turns % 6])
else:
	print(two_first_pos[num_turns % 6])