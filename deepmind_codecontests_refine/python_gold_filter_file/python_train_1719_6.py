s = input()
arr = [-1]
longest_len = 0
count = 1
for j, k in enumerate(s):
    if k == '(':
        arr.append(j)
    elif len(arr) > 1:
        arr.pop()
        mini = j - arr[-1]
        if longest_len < mini:
            longest_len, count = mini, 1
        elif longest_len == mini:
            count += 1
    else:
        arr[0] = j

print(longest_len, count)













	
