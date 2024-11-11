import sys


def parse_array(array_str, n):
	array_str = array_str.split(sep=" ")
	arr = {}
	max_num = 0
	max_num2 = 0
	min_num = sys.maxsize
	min_num2 = sys.maxsize
	for i in range(0, n):
		num = int(array_str[i])
		if num in arr:
			arr[num] = arr[num] + 1
		else:
			arr[num] = 1
		if num > max_num:
			if max_num > max_num2:
				max_num2 = max_num
			max_num = num
		elif num > max_num2:
			max_num2 = num
		if num < min_num:
			if min_num < min_num2:
				min_num2 = min_num
			min_num = num
		elif num < min_num2:
			min_num2 = num
	if n < 2:
		maxw = 0
		minw = 0
	elif n == 2:
		maxw = int(array_str[0]) + int(array_str[1])
		minw = int(array_str[0]) + int(array_str[1])
	else:
		maxw = max_num + max_num2
		minw = min_num + min_num2
	return maxw, minw, arr


def get_max_teams(maxw, minw, arr):
	# print(str(minw) + " " + str(maxw))
	weight_range = range(minw, maxw+1)
	optimal_s = 0
	optimal_teams = 0
	for s in weight_range:
		teams_count = 0
		visited = {}
		for i in arr.keys():
			if not ((s-i) in arr.keys()):
				continue
			if (s-i) in visited:
				continue
			if (s-i) == i:
				new_teams = int(arr[i] / 2)
			else:
				new_teams = min(arr[i], arr[s-i])		
			visited[i] = True
			visited[s-i] = True
			teams_count = teams_count + new_teams
		# print(str(s) + " " + str(teams_count))
		if teams_count > optimal_teams:
			optimal_teams = teams_count
			optimal_s = s
	return optimal_s, optimal_teams


test_cases = int(input(""))
for a in range(0, test_cases):
	n = int(input(""))
	array_str = input("")
	maxw, minw, arr = parse_array(array_str, n)
	s, k = get_max_teams(maxw, minw, arr)
	#print("========> " + str(k))
	print(k)
