m = int(input())

for i in range(m):
    n = int(input())
    arr =list(map(int,input().split(' ')))
    c = 0
    li = []
    for i in range(n):

        ind = 0
        for j in range(n-i):
            if arr[j]>=arr[ind]:
                ind = j
        
        if ind==(n-i-1):
            continue
        c += 1
        l = ind 
        r = n-i-1
        d = l-r
        for k in range(l,r):
            temp = arr[k]
            arr[k] = arr[k+1]
            arr[k+1]= temp
        li.append([l+1,r+1,-d])
    print(c)
    for l in li:
        print(str(l[0])+" "+str(l[1])+" "+str(1))
        


        



    

