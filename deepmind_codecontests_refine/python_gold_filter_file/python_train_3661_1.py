n_q = list(map(int,input().split(" ")))
arr = list(map(int,input().split(" ")))
arr_ind = [i for i in range(n_q[0])]

max_val,max_ind = -1000,-1

for i in range(n_q[0]):
	if(arr[i]>max_val):
		max_val = arr[i]
		max_ind = i

pull = []

for i in range(max_ind+1):
	pull.append([arr[0],arr[1]])
	if(arr[0]>arr[1]):
		temp = arr.pop(1)
		arr.append(temp)
	else:
		temp = arr.pop(0)
		arr.append(temp)
# print(pull)
for i in range(n_q[1]):
	query = int(input())
	if(query<=len(pull)):
		print(*pull[query-1])
	else:
		query-=(len(pull)+1)
		query = query%(len(arr)-1)
		print(str(arr[0])+" "+str(arr[1+query]))


