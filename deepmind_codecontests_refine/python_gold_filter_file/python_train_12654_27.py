import sys
n = int(sys.stdin.readline())
inps = []
zero = False
for i in range(n):
    inps.append(sys.stdin.readline()[:-1].split(' '))
    if zero==False:
        for j in range(len(inps[i])):
            if inps[i][j]=='0':
                zero = [i,j]
                break    
    
ans = -1
if n==1:
    ans = 1
else:
    zeroSum = 0
    for el in inps[zero[0]]:
        el = int(el)            
        zeroSum = zeroSum+el

    line = zero[0]-1
    if line<0:
        line = zero[0]+1
        
    sumLine = 0
    for el in inps[line]:
        el = int(el)
        sumLine = sumLine+el

    zeroValue = sumLine-zeroSum
    if zeroValue <= 0:
        ans = -1    
    else:
        ans = zeroValue
        inps[zero[0]][zero[1]] = zeroValue
        lastSum = sumLine
        for i in range(n):            
            tmpSum = 0
            for el in inps[i]:
                el = int(el)
                tmpSum = tmpSum+el            
            if tmpSum!=lastSum:                
                ans = -1
                break
            lastSum = tmpSum
        if ans!=-1:
            for i in range(n):            
                tmpSum = 0
                for j in range(n):
                    el = int(inps[j][i])
                    tmpSum = tmpSum+el            
                if tmpSum!=lastSum:                
                    ans = -1
                    break
                lastSum = tmpSum
            tmpSum = 0
            tmpSum2 = 0
            for i in range(n):
                el = int(inps[i][i])
                tmpSum = tmpSum+el
                el = int(inps[i][n-i-1])
                tmpSum2 = tmpSum2+el
            if tmpSum!=lastSum:            
                ans = -1
            if tmpSum2!=lastSum:            
                ans = -1
        '''
        sumCol = zeroValue
        for col in range(n):
            el = int(inps[col][zero[1]])
            sumCol=sumCol+el
        if sumCol==sumLine:
            ans = zeroValue
            if zero[0]==zero[1]:
                tmpSum = zeroValue
                for i in range(n):
                    el = int(inps[i][i])
                    tmpSum = tmpSum+el
                if tmpSum!=sumLine:
                    ans = -1

            if zero[0]+zero[1]==n-1:
                tmpSum = zeroValue
                for i in range(n):
                    el = int(inps[i][n-i-1])
                    tmpSum = tmpSum+el
                if tmpSum!=sumLine:
                    ans = -1
        else:
            ans = -1
        '''
      
print(ans)
