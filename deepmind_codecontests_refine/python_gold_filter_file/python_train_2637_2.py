n = int(input())-1
lst = sorted(list(map(int , input().split())))[::-1]
 
ans , i = 0 , 0 
 
while i <= n :
    ans += 1
    carry  = 4 - lst[i]
    #print(carry)
    while lst[n] <= carry and i <= n :
        carry -= lst[n]
        n -= 1
 
    i+=1
print(ans)