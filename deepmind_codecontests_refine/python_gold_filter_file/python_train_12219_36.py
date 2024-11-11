n = int(input())
c,bi,b = 0,0,0
x = list(map(int,input().split()))
result ={}
counter =1
for i in x:
    if counter in result.keys():
        result[counter] +=i
    else:
        result[counter] =i
    counter +=1
    if counter>3:
        counter =1
l = max(result.values())
if result[1] ==l:
    print("chest")
elif result[2] ==l:
    print("biceps")
else:
    print("back")
    

