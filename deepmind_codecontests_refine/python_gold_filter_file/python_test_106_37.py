t=int(input())
for i in range(t):
    n=int(input())
    arr=[]
    if(n==1):
        print(1)
    else:
        arr.append(2)
        i=1
        while(1):
            if(len(arr)==n):
                break
            arr.append(arr[i-1]+1)
            i+=1 
        for k in arr:
            print(k,end=" ")
        print(end="\n")
        