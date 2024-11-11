def lastUnset(n):
    if(n & (n+1) == 0):
        return 0
    pos, temp, count = 0, N, 0
    while temp: 
        # if temp L.S.B is zero 
        # then unset bit pos is 
        # change 
        if not (temp & 1): 
            pos = count  
              
        count += 1; temp>>=1
    return pos+1
N = int(input())
count = 0
Ans = []
while(N & (N+1) != 0):
    pos = lastUnset(N)
    Mask = (1<<pos) - 1
    N ^= Mask
    Ans.append(pos)
    count += 1
    if(N & (N+1) == 0):
        break
    N+=1
    count+=1
print(count)
print(*Ans)