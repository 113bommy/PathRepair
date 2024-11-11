n=int(input())
arr=[]
s=input()
s=s.lower()
for x in s:
    if x not in arr:
        arr.append(x)
if len(arr)==26:
    print("YES")
else :
    print("NO")

