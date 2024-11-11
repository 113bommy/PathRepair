n = int(input())

for _ in range(n):
    s = input()
    if(len(s)==1):
        print("YES")
        continue
    arr = []
    for word in s:
        arr.append(ord(word))

    no = False

    arr.sort(reverse=True)
    for i in range(1,len(arr)):
        if arr[i-1]-arr[i]>1:
            no =True
            break
        if arr[i-1] - arr[i] ==0:
            no =True
            break

    if no:
        print("NO")
        continue
    else:
        print("YES")
        continue   


