t = int(input())
for x in range(t):
    n = int(input())
    currStr = ""
    for y in range(n):
        currStr += input()
    charCount = {}
    for x in currStr:
        if x not in charCount:
            charCount[x] = 1
        else:
            charCount[x] += 1
 
    ans = "yes"
    for x in charCount.items():
        if x[1] % n != 0:
            ans = "no"
 
    print(ans)