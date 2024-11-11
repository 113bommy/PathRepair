def countall(string, substring):
    total = 0
    for i in range(len(string)-len(substring)+1):
        if string[i:i+len(substring)] == substring:
            total += 1
    return total

n = input()
allvalues = []
for i in range(len(n)):
    for j in range(len(n)-1, i-1, -1):
        if countall(n, n[i:j+1]) > 1:
            allvalues.append(j-i+1)
            break

try:
    print(max(allvalues))
except:
    print(0)