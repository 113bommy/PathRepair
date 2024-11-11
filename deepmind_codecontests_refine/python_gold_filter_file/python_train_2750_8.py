from collections import defaultdict
my_dict = defaultdict(lambda: 0)

n = int(input())
l = list(map(int, input().split()))

for num in l:
	my_dict[num] += 1
	
print(my_dict[max(my_dict, key=my_dict.get)],len(my_dict)) 