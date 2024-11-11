q = int(input())
 
while q>0:
    n = int(input())
    a = [ int(v) for v in input().split()]
    a.sort()
    left = 0
    right = len(a)-1
    area = -1
    flag = 0
    while left<right:
        #print(area)
        #new = a[left]*a[right]
        #print(new)
        if area == -1:
            area = a[left] * a[right]
            if((not a[left+1]==a[left]) or (not a[right-1]==a[right])):
                flag = 1
                break
        elif not area == (a[left]*a[right]) or ((not a[left+1]==a[left]) or (not a[right-1]==a[right])):
            flag = 1
            break
        left += 2
        right -= 2
    if flag == 0:
        print("YES")
    else:
        print("NO")
 
    q -= 1
