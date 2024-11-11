n = int(input())
s = input()

s1 = list(s[:n])
s1.sort()

s2 = list(s[n:])
s2.sort()
#print(s1,s2)
if s1[0] == s2[0]:
    print("NO")    
    
elif s1[0] > s2[0]:
    flag = 0
    for i in range(1,n):
        if s1[i] <= s2[i]:
            flag = 1
            #print(s1[i], s2[i])
            break
    
    if flag == 0:
        print("YES")
    else:
        print("NO")

else:
    flag = 0
    for i in range(1,n):
        if s1[i] >= s2[i]:
            flag = 1
            #print(s1[i], s2[i])
            break
    
    if flag == 0:
        print("YES")
    else:
        print("NO")