s=input()
s=s.split(" ")
arr=[]
for i in range(len(s)):
    arr.append(int(s[i]))
arr=sorted(arr)
if(arr[1]==1):
    print("1/1")
elif(arr[1]==2):
    print("5/6")
elif(arr[1]==3):
    print("2/3")
elif(arr[1]==4):
    print("1/2")
elif(arr[1]==5):
    print("1/3")
elif(arr[1]==6):
    print("1/6")