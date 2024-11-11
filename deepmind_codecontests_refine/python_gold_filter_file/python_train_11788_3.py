for _ in range(int(input())):
    inp = input()
    start = None
    end = None
    res = 0

    for i in range(len(inp)):
        char = inp[i]

        if (char == '1'):
            if (start == None):
                start = i

            end = i
    
    if (start != None):
        for char in inp[start:end+1]:
            if (char == '0'):
                res += 1
    
    print(res)
