n = int(input())
resList = [0]*(2*n-1)
resList[-1] = 1
for i in range(2*n-2):
    for i in range(2*n-2):
        resList[i] += resList[i+1]
print(max(resList))