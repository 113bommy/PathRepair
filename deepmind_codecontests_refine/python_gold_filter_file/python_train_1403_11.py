instr, days = (int(x) for x in input().split())
# print (instr, days)
arr = [(int(y), x+1) for x, y in enumerate(input().split())]
#print(arr)
arr.sort()
#print(arr)
sum_per = 0
answer = []
for pair in arr:
    sum_per += pair[0]
    if sum_per > days:
        sum_per -= pair[0]
        break
    else:
        answer.append(str(pair[1]))
print (len(answer))
if sum_per != 0:
    print (" ".join(answer))
    
    
    
