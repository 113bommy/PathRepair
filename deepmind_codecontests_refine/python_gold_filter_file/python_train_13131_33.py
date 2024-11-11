a=input().lower()
b=input().lower()
for i in range(len(a)):
    if a[i]>b[i]:
        print("1")
        break
    elif a[i]<b[i]:
        print("-1")
        break
    elif i==len(a)-1:
        print("0")