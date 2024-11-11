import time

def getZero(arr):
    ans = []

    for i in range(len(arr)):
        if arr[i][0] == 0:
            ans.append(i)

    return ans

for _ in range(int(input())):
    
    s = [ord(i) for i in input()]
    m = int(input())
    arr = [[int(val), i] for i, val in enumerate(input().split())]

    temp = {}
    for i in s:
        if temp.get(i) != None:
            temp[i] += 1
        else:
            temp[i] = 1
    
    s = list(temp.items())
    s.sort(reverse=True)

    resp = [0 for i in range(m)]

    put = 0
    cont = 0
    while cont < m:

        x = getZero(arr)
        while (len(x) > s[0][1]):
            del s[0]

        for j in x:
            val, pos = arr[j]
            resp[pos] = s[0][0]
            cont += 1

            for k in range(len(arr)):
                valAt, posAt = arr[k]

                arr[k][0] -= abs(pos - posAt)

        del s[0]
        
        for j in x:
            arr[j][0] = -1
        
        # print(arr)
        # print(resp)

    for i in resp:
        print(chr(i), end="")
    print()
    # print()
    
