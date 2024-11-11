a=input()
b=input().split()
for i in range(5):
    if(a[0]==b[i][0]):
        print("YES")
        exit()
for i in range(5):
    if(a[1]==b[i][1]):
        print("YES")
        exit()
print("NO")