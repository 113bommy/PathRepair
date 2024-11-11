s=input()
h='hello'
i=0
for j in s:
    if(j==h[i]):
        i=i+1
    if(i==5):
        print("YES")
        break
else:
    print("NO")
