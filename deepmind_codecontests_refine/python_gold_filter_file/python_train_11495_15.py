n=int(input())
z=list(map(int,input().split()))

arr=[0,0,0]
status=True
for i in range(n) :
    if z[i]==25 :
        arr[0]+=1
    elif z[i]==50 :
        arr[1]+=1
        if arr[0]>0 :
            arr[0]-=1
        else :
            status=False
            break
    else :
        arr[2]+=1
        if arr[1]>0 and arr[0] >0 :
            arr[1]-=1
            arr[0]-=1
        elif arr[0]>2:
            arr[0]-=3
        else :
            status=False
            break

if status :
    print("YES")
else :
    print("NO")



















##
##arr=[]
##status=True
##for i in range(n) :
##    if z[i]==25 :
##        arr.append(25)
##    else :
##        hasil=z[i]-25
##        if hasil in arr :
##            arr.remove(hasil)
##        else :
##            if sum(arr) >= hasil :
##                if z[i]==100 :
##                    if 25 in arr and 50 in arr :
##                        arr.remove(25)
##                        arr.remove(50)
##                    else :
##                        arr.remove(25)
##                        arr.remove(25)
##                        arr.remove(25)
##            else:
##                status=False
##                break
##        arr.append(z[i])
##
##if status :
##    print("YES")
##else :
##    print("NO")

