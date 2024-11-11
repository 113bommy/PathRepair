from math import ceil

for _ in range(int(input())):
    n=int(input())
    s=input().strip()
    flag=1
    for i in range(ceil(n)):
        #print(ord(s[i])-1!=ord(s[n-i-1])-1,ord(s[i])-1!=ord(s[n-i-1])+1,ord(s[i])+1!=ord(s[n-i-1])-1,ord(s[i])+1!=ord(s[n-i-1])+1)
        if ord(s[i])-1!=ord(s[n-i-1])-1 and ord(s[i])-1!=ord(s[n-i-1])+1 and ord(s[i])+1!=ord(s[n-i-1])-1 and ord(s[i])+1!=ord(s[n-i-1])+1:
            flag=0 
            break
    if flag==1:
        print("YES")
    else:
        print("NO")
        
    