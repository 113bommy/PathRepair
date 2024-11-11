for _ in range(int(input())):
    rem = 0
    ans = ""
    lCount = rCount = uCount = dCount = 0
    s = input()
    for var in s:
        if var=='L': lCount += 1
        elif var=='R': rCount += 1
        elif var=='U': uCount += 1
        else: dCount += 1
    L = min(lCount,rCount) 
    R = min(uCount,dCount) 
    if L == 0 and R == 0: ans = ''
    elif L != 0 and R == 0: ans = 'LR'
    elif L == 0 and R != 0: ans = 'UD'
    else:ans = 'L'*min(lCount,rCount)+'U'*min(uCount,dCount)+'R'*min(lCount,rCount)+'D'*min(uCount,dCount)
    print(len(ans))
    print(ans)
  