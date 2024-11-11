n, k, p, x, y = list(map(int, input().split()))

marks = list(map(int, input().split()))

marks.sort()

less = 0
more = 0
equal = 0
midway = (n+1)//2

final = []


for i in marks:
    if i < y:
        less+=1
    elif i == y:
        equal+=1        
    else:
        more+=1
        
if less >= midway:
    print(-1)
    
#elif more >= (n+1)/2 or (more + equal) >= (n+1/2):
elif (more + equal) >= midway:
    final.extend((n-k)*[1])

    if sum(final) + sum(marks) <= x: # redundancy. Need to refactor as this if-else block repeats in the final else as well
        for i in range(len(final)):
            print(final[i], end=' ')
    else: print(-1)

else:

    final.extend((midway -1 - less)*[1])

    
    final.extend((midway - (more + equal))*[y])

    if sum(final) + sum(marks) <= x:
        for i in range(len(final)):
            print(final[i], end=' ')
    else: print(-1) 





##mode = marks[(n+1)//2 - 1]
##
##if (n+1)/2 <= k:    
##    if mode < y:
##        print('mode',-1)
##    else:
##        for i in range(k, n):            
##            marks.append(marks[k-1])
##        if sum(marks) > x:
##            print(marks)
##            print('sum',-1)
##        else:
##            for i in range(k, n):
##                print(marks[i], end=' ')
##else:
##    for i in range(k+1, n+1):
##        if i < mode:
##            marks.append(marks[k-1])
##        else:
##            marks.append(y)
##
##    for i in range(k+1, n+1):
##        print(marks[i], end=' ')

        
