from collections import Counter
for _ in range(int(input())):
    p=input()
    h=input()
    flag=0
    for i in range(0, len(h)):
        if Counter(h[i:i+len(p)])==Counter(p):
            flag=1
            
    if flag==1:
        print("YES")
    else:
        print("NO")
    